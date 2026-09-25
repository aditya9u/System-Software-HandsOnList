#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    mkfifo("fifo1", 0666);
    mkfifo("fifo2", 0666);

    int fd1 = open("fifo1", O_WRONLY);
    write(fd1, "Sender sending...\n", 18);

    int fd2 = open("fifo2", O_RDONLY);
    char buf[50];
    read(fd2, buf, sizeof(buf));
    printf("Receiver replied: %s\n", buf);

    close(fd1); close(fd2);
    return 0;
}