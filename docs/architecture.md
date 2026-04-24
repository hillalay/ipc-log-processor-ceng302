# Architecture

## Purpose

This project implements two IPC approaches for the same producer-consumer scenario:

- Named Pipe (FIFO)
- POSIX Shared Memory + Semaphore

Both implementations should provide equivalent behavior to compare communication strategies.

## Components

- Producer applications:
  - myData_pipe
  - myData_shm
- Consumer applications:
  - myMore_pipe
  - myMore_shm

## High-Level Flow

1. Producer reads log files.
2. Producer sends or exposes data pages to consumer.
3. Consumer displays output page-by-page.
4. Consumer input controls pagination and quit behavior.

## Non-Functional Goals

- Correct synchronization under concurrent execution
- Deterministic cleanup of IPC resources
- Clear error handling and diagnostics

## Deliverable Contract

Final test execution expects these source files at repository root:

- myData_pipe.c
- myMore_pipe.c
- myData_shm.c
- myMore_shm.c
