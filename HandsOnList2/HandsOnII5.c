#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Max length of exec args: %long\n", sysconf(_SC_ARG_MAX));
    printf("Max simultaneous processes per UID: %long\n", sysconf(_SC_CHILD_MAX));
    printf("Clock ticks (jiffy) per sec: %long\n", sysconf(_SC_CLK_TCK));
    printf("Max number of open files: %long\n", sysconf(_SC_OPEN_MAX));
    printf("Page size: %long bytes\n", sysconf(_SC_PAGESIZE));
    printf("Total physical pages: %long\n", sysconf(_SC_PHYS_PAGES));
    printf("Available physical pages: %long\n", sysconf(_SC_AVPHYS_PAGES));
    return 0;
}