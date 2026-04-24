#include "common_shm.h"

int shm_fd;
struct shared_data *shared_ptr;
sem_t *sem_prod;
sem_t *sem_cons;

// Sinyal yakalandığında kaynakları temizler 
void cleanup_handler(int sig) {
    printf("\n[Producer] Kaynaklar temizleniyor...\n");
    munmap(shared_ptr, SHM_SIZE);
    close(shm_fd);
    sem_close(sem_prod);
    sem_close(sem_cons);
    shm_unlink(SHM_NAME);
    sem_unlink(SEM_PROD);
    sem_unlink(SEM_CONS);
    exit(0);
}

// Her dosya için çalışan threads fonksiyonu
void* read_logs(void* arg) {
    char* filename = (char*)arg;
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Dosya acilamadi");
        pthread_exit(NULL);
    }

    char line[MAX_LOG_LEN];
    while (fgets(line, sizeof(line), file)) {
        sem_wait(sem_prod); // Yazmak için izin bekleme
        strncpy(shared_ptr->log_line, line, MAX_LOG_LEN);
        shared_ptr->is_finished = 0;
        sem_post(sem_cons); // Tüketiciye haber verme 
    }

    fclose(file);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Kullanim: %s <log1> <log2> ...\n", argv[0]);
        return 1;
    }

    signal(SIGINT, cleanup_handler);

    // Shared Memory ve Semafor kurulumu 
    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SHM_SIZE);
    shared_ptr = (struct shared_data *)mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    sem_prod = sem_open(SEM_PROD, O_CREAT, 0666, 1);
    sem_cons = sem_open(SEM_CONS, O_CREAT, 0666, 0);

    pthread_t threads[argc - 1];
    for (int i = 1; i < argc; i++) {
        pthread_create(&threads[i-1], NULL, read_logs, (void*)argv[i]);
    }

    for (int i = 0; i < argc - 1; i++) {
        pthread_join(threads[i], NULL);
    }

    // Bitiş sinyali gönder
    sem_wait(sem_prod);
    shared_ptr->is_finished = 1;
    sem_post(sem_cons);

    printf("[Producer] Islem tamamlandi.\n");
    return 0;
}