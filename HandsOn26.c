#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"/bin/echo", "Hello from executed binary", NULL};
    execv(args[0], args);
    return 0;
}