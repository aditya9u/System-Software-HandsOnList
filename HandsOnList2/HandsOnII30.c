#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = ftok(".", 'b');
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char *str = (char*) shmat(shmid, NULL, 0);
    strcpy(str, "Shared Memory Data");
    printf("Data written: %s\n", str);
    shmdt(str);

    // Read only attach
    char *ro_str = (char*) shmat(shmid, NULL, SHM_RDONLY);
    printf("Read-only access: %s\n", ro_str);
    shmdt(ro_str);

    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}