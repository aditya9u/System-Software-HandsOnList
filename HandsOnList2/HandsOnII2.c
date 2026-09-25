#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit rlim;
    if (getrlimit(RLIMIT_NOFILE, &rlim) == 0) {
        printf("Open Files Soft Limit: %ld\n", (long)rlim.rlim_cur);
        printf("Open Files Hard Limit: %ld\n", (long)rlim.rlim_max);
    }
    if (getrlimit(RLIMIT_STACK, &rlim) == 0) {
        printf("Stack Size Soft Limit: %ld bytes\n", (long)rlim.rlim_cur);
        printf("Stack Size Hard Limit: %ld bytes\n", (long)rlim.rlim_max);
    }
    return 0;
}