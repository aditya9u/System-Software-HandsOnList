#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    if (fork() == 0) {
        printf("Child (PID %d): Killing Parent (PID %d)...\n", getpid(), getppid());
        kill(getppid(), SIGKILL);
        sleep(2);
        printf("Child became Orphan. New Parent PID: %d\n", getppid());
    } else {
        while (1) pause();
    }
    return 0;
}