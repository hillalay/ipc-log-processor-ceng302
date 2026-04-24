# Test Protocol

## Goal

Standardize local test execution and reporting.

## Prerequisites

- gcc available in shell
- bash-compatible runner for scripts/test_script.sh
- POSIX-compatible toolchain (Linux/WSL recommended)

## Environment Warning

If your compiler cannot find headers such as `pthread.h` or `semaphore.h`, your environment is not POSIX-ready for this assignment.
Use WSL (Ubuntu) or a Linux machine for reliable execution.

## Script Contract

When running scripts/test_script.sh from repository root, these files must exist at repository root:

- myData_pipe.c
- myMore_pipe.c
- myData_shm.c
- myMore_shm.c
- web_server_logs.txt
- db_server_logs.txt

## Recommended Flow

1. Build and run script.
2. Capture terminal output.
3. Save concise result summary under test/test-report.
4. Record failures and fixes in docs/known-issues.md.
