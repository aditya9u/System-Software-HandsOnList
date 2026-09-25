#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

union semun {
    int val;
};

int main() {
    key_t key = ftok(".", 'c');
    int semid = semget(key, 2, 0666 | IPC_CREAT);

    union semun arg;
    
    // Binary Semaphore (0)
    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);

    // Counting Semaphore (1)
    arg.val = 5;
    semctl(semid, 1, SETVAL, arg);

    printf("Binary and Counting Semaphores initialized.\n");
    return 0;
}