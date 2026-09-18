#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) return 1;
    struct stat sb;
    if (lstat(argv[1], &sb) == -1) return 1;

    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:  printf("Block device\n"); break;
        case S_IFCHR:  printf("Character device\n"); break;
        case S_IFDIR:  printf("Directory\n"); break;
        case S_IFIFO:  printf("FIFO/pipe\n"); break;
        case S_IFLNK:  printf("Symlink\n"); break;
        case S_IFREG:  printf("Regular file\n"); break;
        case S_IFSOCK: printf("Socket\n"); break;
        default:       printf("Unknown file type\n"); break;
    }
    return 0;
}