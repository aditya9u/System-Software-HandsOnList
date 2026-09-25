#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Ignoring SIGINT for 5 seconds (Try Ctrl+C)...\n");
    signal(SIGINT, SIG_IGN);
    sleep(5);

    printf("\nResetting SIGINT to default. Press Ctrl+C to terminate...\n");
    signal(SIGINT, SIG_DFL);
    while (1) pause();
    return 0;
}