#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    key_t key = ftok(".", 'a');
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct msgbuf msg;

    // Receive message with IPC_NOWAIT flag
    if (msgrcv(msgid, &msg, sizeof(msg.mtext), 1, IPC_NOWAIT) != -1) {
        printf("Received Message: %s\n", msg.mtext);
    } else {
        perror("msgrcv with IPC_NOWAIT failed");
    }
    return 0;
}