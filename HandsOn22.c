#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("fork_test.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fork() == 0) {
        write(fd, "Written by Child\n", 17);
    } else {
        write(fd, "Written by Parent\n", 18);
    }
    close(fd);
    return 0;
}