# Unnamed Semaphore Demo

This project demonstrates the use of POSIX unnamed semaphores for thread synchronization within a single process using pthreads in Linux.

## Files

- `sem4_demo.c`: Example code showing two threads synchronizing access to a critical section using an unnamed semaphore.

## Build

Compile with:

```sh
gcc sem4_demo.c -o sem4_demo -lpthread
```

## Usage

Run the program:

```sh
./sem4_demo
```

You will see output indicating when each thread enters and exits the critical section, demonstrating mutual exclusion.

## Requirements

- Linux system
- GCC
- POSIX threads and semaphore support

## Explanation -

2 threads are being created, one 2 seconds after the first one. But the first thread will sleep for 4 seconds after acquiring the lock.
Thus the second thread will not enter immediately after it is called, it will enter 4 - 2 = 2 secs after it is called. So the output is:

```
Entered..
Just Exiting...
Entered..
Just Exiting...
```

but not:

```
Entered..
Entered..
Just Exiting...
Just Exiting...
```