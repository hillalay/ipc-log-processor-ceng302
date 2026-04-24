#ifndef COMMON_SHM_H
#define COMMON_SHM_H

/* Standard library inclusions for IPC and threading */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <semaphore.h>
#include <signal.h>
#include <pthread.h>

/* IPC Resource Identifiers: Unique names for system-wide access */
#define SHM_NAME "/ceng302_log_shm"
#define SEM_PROD "/sem_ceng302_producer"
#define SEM_CONS "/sem_ceng302_consumer"

/* Buffer and Memory Constraints */
#define MAX_LOG_LEN 1024  // Maximum characters per log entry
#define SHM_SIZE 4096     // Total allocated shared memory segment size

/* Shared Data Structure: Mapping the memory layout for Producer and Consumer */
struct shared_data {
    char log_line[MAX_LOG_LEN]; // Buffer for the current log record
    int is_finished;            // Status flag: 1 indicates EOF for all files
};

#endif