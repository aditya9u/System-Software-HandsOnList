#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    mkfifo("one_way_fifo", 0666);
    int fd = open("one_way_fifo", O_WRONLY);
    write(fd, "One way FIFO messaging\n", 23);
    close(fd);
    return 0;
}