#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

#define FIFO_NAME "/tmp/my_log_pipe"

void* read_file(void* arg) {
    char* file = (char*)arg;
    FILE* f = fopen(file, "r");
    if(!f) return NULL;
    
    char line[1024];
    int fd = open(FIFO_NAME, O_WRONLY);
    while (fgets(line, sizeof(line), f)) {
        write(fd, line, strlen(line));
    }
    fclose(f);
    close(fd);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    
    // Boruyu burada oluşturuyoruz
    mkfifo(FIFO_NAME, 0666);
    printf("[Producer] Boru oluşturuldu, veri gönderilecek...\n");

    pthread_t t;
    pthread_create(&t, NULL, read_file, argv[1]);
    pthread_join(t, NULL);
    
    return 0;
}
