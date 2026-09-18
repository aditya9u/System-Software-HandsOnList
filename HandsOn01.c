#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    // Note: Ensure target.txt exists before running
    if (symlink("target.txt", "soft_link.txt") == 0)
        printf("Soft link created using symlink system call.\n");
    if (link("target.txt", "hard_link.txt") == 0)
        printf("Hard link created using link system call.\n");
    if (mkfifo("my_fifo", 0666) == 0)
        printf("FIFO created using mkfifo system call.\n");
    return 0;
}