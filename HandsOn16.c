#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    struct flock fl = {F_WRLCK, SEEK_SET, 0, 0, 0};
    int fd = open("lock_file.txt", O_RDWR | O_CREAT, 0666);
    
    printf("Acquiring Write Lock...\n");
    fcntl(fd, F_SETLKW, &fl);
    printf("Write Lock acquired. Press Enter to unlock...\n");
    getchar();

    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &fl);
    printf("Unlocked.\n");

    close(fd);
    return 0;
}