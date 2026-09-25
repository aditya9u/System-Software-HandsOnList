#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {AF_INET, htons(8080), INADDR_ANY};

    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 5);

    printf("Concurrent server started on port 8080...\n");
    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        if (fork() == 0) {
            close(server_fd);
            write(client_fd, "Connected to concurrent server\n", 31);
            close(client_fd);
            return 0;
        }
        close(client_fd);
    }
    return 0;
}