#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit rlim;
    rlim.rlim_cur = 512;
    rlim.rlim_max = 1024;

    if (setrlimit(RLIMIT_NOFILE, &rlim) == 0) {
        printf("Successfully updated open files limit!\n");
    } else {
        perror("setrlimit failed");
    }
    return 0;
}