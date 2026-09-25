#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key = ftok(".", 'a');
    int msgid = msgget(key, 0666 | IPC_CREAT);
    printf("Key: %d\nMessage Queue ID: %d\n", key, msgid);
    return 0;
}