#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sig_action_handler(int sig, siginfo_t *info, void *context) {
    printf("sigaction caught signal: %d\n", sig);
    exit(0);
}

int main() {
    struct sigaction sa;
    sa.sa_sigaction = sig_action_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGINT, &sa, NULL);
    printf("Waiting for SIGINT via sigaction...\n");
    while (1) pause();
    return 0;
}