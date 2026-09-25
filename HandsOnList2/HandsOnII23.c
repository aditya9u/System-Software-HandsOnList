#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef F_GETPIPE_SZ
#define F_GETPIPE_SZ 1024
#endif

int main() {
    int fd[2];
    pipe(fd);
    printf("Max Open Files Limit: %long\n", sysconf(_SC_OPEN_MAX));
    printf("Pipe Buffer Size: %d bytes\n", fcntl(fd[0], F_GETPIPE_SZ));
    close(fd[0]); close(fd[1]);
    return 0;
}