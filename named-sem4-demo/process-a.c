#include <stdio.h>
#include <unistd.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int i = 0;

int main() {
    printf("Process A started, PID: %d\n", getpid());

    sem_t *semA = sem_open("/semA", O_CREAT, 0644, 1);
    sem_t *semB = sem_open("/semB", O_CREAT, 0644, 0);
    if (semA == SEM_FAILED || semB == SEM_FAILED) {
        printf("sem_open failed\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("sem_open success\n");
    }

    printf("Process A %d successfully opened semaphores\n", getpid());
    // Keep the process alive using an infinite loop
    while (1) {
        sem_wait(semB); // P operation
        i++;
        printf("Process A %d entered critical section for the %d time\n", getpid(), i);
        sleep(10); // Print every 10 seconds to avoid high CPU usage
        printf("Process A %d leaving critical section\n", getpid());
        sem_post(semA); // V operation
        if (i >= 5)
        {
            printf("Process A %d finished 5 operations, preparing to exit\n", getpid());
            break; // Exit loop
        }
    }

    sem_close(semA);
    sem_close(semB);
    sem_unlink("/semA");
    sem_unlink("/semB");

    return 0;
}