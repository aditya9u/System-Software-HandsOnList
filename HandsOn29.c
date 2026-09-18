#include <stdio.h>
#include <sched.h>
#include <unistd.h>

int main() {
    struct sched_param param;
    int policy = sched_getscheduler(0);
    printf("Current Scheduling Policy: %d\n", policy);

    param.sched_priority = 10;
    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler failed (run as root)");
    } else {
        printf("Policy successfully updated to SCHED_FIFO\n");
    }
    return 0;
}