#include <stdio.h>
#include <unistd.h>

int main() {
    int p1[2], p2[2];
    pipe(p1); pipe(p2);

    if (fork() == 0) {
        close(p1[1]); close(p2[0]);
        char buf[30];
        read(p1[0], buf, sizeof(buf));
        printf("Child got: %s\n", buf);
        write(p2[1], "Hello Parent", 13);
    } else {
        close(p1[0]); close(p2[1]);
        write(p1[1], "Hello Child", 12);
        char buf[30];
        read(p2[0], buf, sizeof(buf));
        printf("Parent got: %s\n", buf);
    }
    return 0;
}