#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    if (fork() > 0) exit(0); // Parent exits
    setsid();                // Create new session
    chdir("/");
    umask(0);

    while (1) {
        // Simple Daemon task executing every 30 seconds
        system("date >> /tmp/daemon_log.txt");
        sleep(30);
    }
    return 0;
}