#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <src> <dest>\n", argv[0]);
        return 1;
    }
    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buf[1024];
    int n;
    while ((n = read(fd1, buf, sizeof(buf))) > 0) {
        write(fd2, buf, n);
    }
    close(fd1);
    close(fd2);
    return 0;
}