#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    if (fork() == 0) {
        printf("Child process running... Parent PID: %d\n", getppid());
        sleep(10);
        printf("Child becomes Orphan... New Parent PID (init/systemd): %d\n", getppid());
    } else {
        printf("Parent exiting...\n");
        exit(0);
    }
    return 0;
}