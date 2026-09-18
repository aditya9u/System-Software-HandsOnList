#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
    fd_set readfds;
    struct timeval tv;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    printf("Waiting for input for 10 seconds...\n");
    int retval = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv);

    if (retval == -1) perror("select error");
    else if (retval) printf("Data is available now!\n");
    else printf("No data within 10 seconds.\n");

    return 0;
}