#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = creat("created_file.txt", 0644);
    if (fd < 0) {
        perror("creat failed");
        return 1;
    }
    printf("File Descriptor value: %d\n", fd);
    close(fd);
    return 0;
}