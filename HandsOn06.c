#include <unistd.h>

int main() {
    char buf[1024];
    int n = read(STDIN_FILENO, buf, sizeof(buf));
    if (n > 0) {
        write(STDOUT_FILENO, buf, n);
    }
    return 0;
}