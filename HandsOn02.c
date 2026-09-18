#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Process PID: %d\n", getpid());
    printf("Check /proc/%d for process details.\n", getpid());
    while (1);
    return 0;
}