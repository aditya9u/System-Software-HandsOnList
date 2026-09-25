#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Timer expired (Signal: %d)\n", sig);
}

int main() {
    struct itimerval timer;
    signal(SIGALRM, handler);
    
    // Set 10 seconds and 10 microseconds interval/value
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    setitimer(ITIMER_REAL, &timer, NULL);
    printf("ITIMER_REAL set. Waiting...\n");
    pause();
    return 0;
}