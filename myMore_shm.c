#include "common_shm.h"

int shm_fd;
struct shared_data *shared_ptr;
sem_t *sem_prod;
sem_t *sem_cons;

void cleanup(int sig) {
    munmap(shared_ptr, SHM_SIZE);
    close(shm_fd);
    sem_close(sem_prod);
    sem_close(sem_cons);
    exit(0);
}

int main() {
    signal(SIGINT, cleanup);

    shm_fd = shm_open(SHM_NAME, O_RDWR, 0666);
    shared_ptr = (struct shared_data *)mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    sem_prod = sem_open(SEM_PROD, 0);
    sem_cons = sem_open(SEM_CONS, 0);

    int count = 0;
    while (1) {
        sem_wait(sem_cons); // Veri gelmesini bekle 
        if (shared_ptr->is_finished) break;

        // Filtreleme: Sadece ERROR ve CRITICAL 
        if (strstr(shared_ptr->log_line, "ERROR") || strstr(shared_ptr->log_line, "CRITICAL")) {
            printf("%s", shared_ptr->log_line);
            count++;

            // Sayfalama: Her 10 satırda bir dur 
            if (count % 10 == 0) {
                printf("\n-- Devam etmek icin bosluk, cikmak icin q tusuna basin --\n");
                char c = getchar();
                if (c == 'q' || c == 'Q') break;
            }
        }
        sem_post(sem_prod); 
    }

    cleanup(0);
    return 0;
}