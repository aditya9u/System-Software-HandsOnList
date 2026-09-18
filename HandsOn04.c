#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int fd = open("test_excl.txt", O_RDWR | O_CREAT | O_EXCL, 0644);
    if (fd < 0) {
        perror("open O_EXCL failed (file likely exists)");
    } else {
        printf("File opened successfully with O_EXCL. FD: %d\n", fd);
        close(fd);
    }
    return 0;
}