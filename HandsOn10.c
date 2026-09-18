#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("lseek_test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    write(fd, "0123456789", 10);
    off_t offset = lseek(fd, 10, SEEK_CUR);
    printf("lseek returned offset: %ld\n", (long)offset);
    write(fd, "0123456789", 10);
    close(fd);
    return 0;
}