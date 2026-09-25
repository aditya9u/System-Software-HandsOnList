#include <stdio.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    pipe(pipefd);

    if (fork() == 0) {
        close(pipefd[1]);
        char buf[30];
        read(pipefd[0], buf, sizeof(buf));
        printf("Child received: %s\n", buf);
        close(pipefd[0]);
    } else {
        close(pipefd[0]);
        write(pipefd[1], "Message from Parent", 20);
        close(pipefd[1]);
    }
    return 0;
}