#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) return 1;
    int fd = open(argv[1], O_RDWR);
    int flags = fcntl(fd, F_GETFL);
    int accmode = flags & O_ACCMODE;

    if (accmode == O_RDONLY) printf("Read Only\n");
    else if (accmode == O_WRONLY) printf("Write Only\n");
    else if (accmode == O_RDWR) printf("Read Write\n");

    close(fd);
    return 0;
}