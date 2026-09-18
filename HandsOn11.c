#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("dup_test.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
    int fd_dup = dup(fd);
    int fd_dup2 = dup2(fd, 10);
    int fd_fcntl = fcntl(fd, F_DUPFD, 0);

    write(fd, "Line via original fd\n", 21);
    write(fd_dup, "Line via dup fd\n", 16);
    write(fd_dup2, "Line via dup2 fd\n", 17);
    write(fd_fcntl, "Line via fcntl fd\n", 18);

    close(fd); close(fd_dup); close(fd_dup2); close(fd_fcntl);
    return 0;
}