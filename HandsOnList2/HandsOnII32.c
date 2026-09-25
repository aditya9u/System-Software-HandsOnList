#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

int main() {
    key_t key = ftok(".", 'd');
    int semid = semget(key, 1, 0666 | IPC_CREAT);

    struct sembuf p = {0, -1, 0};
    struct sembuf v = {0, 1, 0};

    printf("Entering Critical Section...\n");
    semop(semid, &p, 1);
    
    printf("Inside Critical Section! Operations protected.\n");
    sleep(1);

    semop(semid, &v, 1);
    printf("Exited Critical Section.\n");

    semctl(semid, 0, IPC_RMID);
    return 0;
}