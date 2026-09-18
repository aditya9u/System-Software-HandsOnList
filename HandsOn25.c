#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pids[3];
    for (int i = 0; i < 3; i++) {
        if ((pids[i] = fork()) == 0) {
            sleep(i + 1);
            exit(0);
        }
    }
    printf("Parent waiting specifically for 2nd child (PID: %d)...\n", pids[1]);
    waitpid(pids[1], NULL, 0);
    printf("Child 2 finished execution.\n");
    return 0;
}