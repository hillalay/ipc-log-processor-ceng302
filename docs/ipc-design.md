# IPC Design Notes

## Named Pipe Path

### APIs

- mkfifo
- open/read/write/close

### Expected Behavior

- Producer creates/opens FIFO safely.
- Consumer reads stream in expected ordering.
- Program handles startup order gracefully where possible.

## Shared Memory Path

### APIs

- shm_open
- ftruncate
- mmap
- sem_open / sem_wait / sem_post

### Expected Behavior

- Shared region is initialized once.
- Producer-consumer handoff is semaphore protected.
- Shared resources are unlinked/closed on shutdown.

## Parity Requirement

Pipe and SHM versions should process the same input and produce equivalent user-visible pagination behavior.
