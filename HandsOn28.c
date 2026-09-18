#include <stdio.h>
#include <sched.h>

int main() {
    printf("FIFO Max Priority: %d\n", sched_get_priority_max(SCHED_FIFO));
    printf("FIFO Min Priority: %d\n", sched_get_priority_min(SCHED_FIFO));
    printf("RR Max Priority: %d\n", sched_get_priority_max(SCHED_RR));
    printf("RR Min Priority: %d\n", sched_get_priority_min(SCHED_RR));
    return 0;
}