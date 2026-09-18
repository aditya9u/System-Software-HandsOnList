#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) return 1;
    struct stat sb;
    if (stat(argv[1], &sb) == -1) return 1;

    printf("Inode: %lu\n", (unsigned long)sb.st_ino);
    printf("Hard links: %ld\n", (long)sb.st_nlink);
    printf("UID: %d\n", sb.st_uid);
    printf("GID: %d\n", sb.st_gid);
    printf("Size: %ld bytes\n", (long)sb.st_size);
    printf("Block size: %ld\n", (long)sb.st_blksize);
    printf("Blocks allocated: %ld\n", (long)sb.st_blocks);
    printf("Last access: %ld\n", sb.st_atime);
    printf("Last modification: %ld\n", sb.st_mtime);
    printf("Last change: %ld\n", sb.st_ctime);
    return 0;
}