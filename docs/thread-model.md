# Thread Model

## Minimum Requirement

Each relevant program includes thread creation via pthread_create as required by test checks.

## Threading Guidelines

- Protect shared mutable state with pthread_mutex_lock / pthread_mutex_unlock.
- Keep critical sections minimal.
- Join or detach threads intentionally.
- Propagate thread-level errors to process-level logs.

## Shutdown Expectations

- Handle interruption cleanly where implemented.
- Avoid leaving dangling threads or locked mutexes.
