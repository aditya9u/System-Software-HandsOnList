#include <stdio.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    char buf[20];

    pipe(pipefd);
    write(pipefd[1], "Hello Pipe\n", 11);
    read(pipefd[0], buf, 11);
    write(STDOUT_FILENO, buf, 11);

    close(pipefd[0]);
    close(pipefd[1]);
    return 0;
}