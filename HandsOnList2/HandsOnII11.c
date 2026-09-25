#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    struct sigaction sa_ign, sa_dfl;

    sa_ign.sa_handler = SIG_IGN;
    sigemptyset(&sa_ign.sa_mask);
    sa_ign.sa_flags = 0;

    sa_dfl.sa_handler = SIG_DFL;
    sigemptyset(&sa_dfl.sa_mask);
    sa_dfl.sa_flags = 0;

    sigaction(SIGINT, &sa_ign, NULL);
    printf("Ignoring SIGINT using sigaction (5s)...\n");
    sleep(5);

    sigaction(SIGINT, &sa_dfl, NULL);
    printf("\nReset SIGINT to default via sigaction. Send Ctrl+C now...\n");
    while(1) pause();
    return 0;
}