#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/stat.h>

int main() {
    mkfifo("select_fifo", 0666);
    int fd = open("select_fifo", O_RDWR | O_NONBLOCK);

    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);

    struct timeval tv = {10, 0};
    printf("Waiting 10s for write on FIFO...\n");
    int res = select(fd + 1, &rfds, NULL, NULL, &tv);

    if (res > 0) printf("Data available in FIFO!\n");
    else printf("Timeout: No data written within 10 seconds.\n");

    close(fd);
    return 0;
}