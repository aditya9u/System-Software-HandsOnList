#include <stdio.h>
#include <sys/stat.h>

int main() {
    if (mknod("my_mknod_fifo", S_IFIFO | 0666, 0) == 0)
        printf("FIFO created via mknod system call\n");
    if (mkfifo("my_mkfifo_fifo", 0666) == 0)
        printf("FIFO created via mkfifo library function\n");
    return 0;
}