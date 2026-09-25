#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught signal %d\n", sig);
}

int main() {
    // Note: SIGSTOP cannot be caught or ignored per POSIX standards
    if (signal(SIGSTOP, handler) == SIG_ERR) {
        printf("Cannot catch SIGSTOP! Operating system prevents handling or ignoring SIGSTOP.\n");
    }
    return 0;
}