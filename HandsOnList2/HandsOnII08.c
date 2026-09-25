#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler(int sig) {
    printf("Caught signal: %d\n", sig);
    exit(0);
}

int main() {
    signal(SIGINT, sig_handler);
    printf("Catching SIGINT (Press Ctrl+C)...\n");
    while(1) pause();
    return 0;
}