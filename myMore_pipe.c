#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#define FIFO_NAME "/tmp/my_log_pipe"

void cleanup(int sig) {
    unlink(FIFO_NAME);
    exit(0);
}

int main() {
    signal(SIGINT, cleanup);
    
    // Boru açılmadan önce yazsın ki çalıştığını görelim
    printf("[Consumer] Boru bekleniyor...\n");
    
    int fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("Pipe hatasi");
        return 1;
    }

    printf("[Consumer] Bağlantı kuruldu! Filtreleme başlıyor...\n");

    char c;
    char line[1024];
    int idx = 0;
    while (read(fd, &c, 1) > 0) {
        line[idx++] = c;
        if (c == '\n') {
            line[idx] = '\0';
            if (strstr(line, "ERROR") || strstr(line, "CRITICAL")) {
                printf("LOG: %s", line);
            }
            idx = 0;
        }
    }
    close(fd);
    return 0;
}