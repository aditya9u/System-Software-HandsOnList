#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char filename[20];
    int fds[5];
    printf("PID: %d\nCheck /proc/%d/fd\n", getpid(), getpid());
    for (int i = 0; i < 5; i++) {
        sprintf(filename, "file_%d.txt", i + 1);
        fds[i] = open(filename, O_CREAT | O_RDWR, 0644);
    }
    while (1);
    return 0;
}