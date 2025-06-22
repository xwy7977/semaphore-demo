# Named Semaphore Demo

This project demonstrates the use of POSIX named semaphores for inter-process synchronization in Linux.

## Files

- `process-a.c`: Process A, which waits for Process B to signal before entering the critical section.
- `process-b.c`: Process B, which signals Process A and enters the critical section alternately.

## Build

Compile each process with:

```sh
gcc process-a.c -o process-a -lpthread
gcc process-b.c -o process-b -lpthread
```

## Usage

1. Open two terminals.
2. In the first terminal, run:
    ```sh
    ./process-a
    ```
3. In the second terminal, run:
    ```sh
    ./process-b
    ```

You will see both processes alternately entering and leaving their critical sections, synchronized by named semaphores.

## Cleanup

Semaphores are unlinked at the end of each process. If needed, you can manually remove them:

```sh
sem_unlink("/semA");
sem_unlink("/semB");
```

## Requirements

- Linux system
- GCC
- POSIX semaphore support (`-pthread` flag)

## Results

**Process A**
```
Process A started, PID: 1609887
sem_open success
Process A 1609887 successfully opened semaphores
Process A 1609887 entered critical section for the 1 time
Process A 1609887 leaving critical section
Process A 1609887 entered critical section for the 2 time
Process A 1609887 leaving critical section
Process A 1609887 entered critical section for the 3 time
Process A 1609887 leaving critical section
Process A 1609887 entered critical section for the 4 time
Process A 1609887 leaving critical section
Process A 1609887 entered critical section for the 5 time
Process A 1609887 leaving critical section
Process A 1609887 finished 5 operations, preparing to exit
```

**Process B**
```
Process B started, PID: 1609855
sem_open success
Process B 1609855 successfully opened semaphores
Process B 1609855 entered critical section for the 1 time
Process B 1609855 leaving critical section
Process B 1609855 entered critical section for the 2 time
Process B 1609855 leaving critical section
Process B 1609855 entered critical section for the 3 time
Process B 1609855 leaving critical section
Process B 1609855 entered critical section for the 4 time
Process B 1609855 leaving critical section
Process B 1609855 entered critical section for the 5 time
Process B 1609855 leaving critical section
Process B 1609855 finished 5 operations, preparing to exit
```

**If we follow the chronological order**
```
start
Process B run 10 seconds
Process A run 10 seconds
Process B run 10 seconds
Process A run 10 seconds
Process B run 10 seconds
Process A run 10 seconds
Process B run 10 seconds
Process A run 10 seconds
Process B run 10 seconds
Process A run 10 seconds
Process B run 10 seconds
Process A run 10 seconds
exit
```

## where to find semaphore

```
/dev/shm
```