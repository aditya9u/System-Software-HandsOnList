#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    if (fork() == 0) {
        printf("Child exiting to become Zombie...\n");
        exit(0);
    } else {
        printf("Parent sleeping. Run 'ps aux' to see zombie process.\n");
        sleep(10);
    }
    return 0;
}