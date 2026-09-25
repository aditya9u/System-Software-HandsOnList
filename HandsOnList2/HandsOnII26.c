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
    struct msgbuf msg = {1, "Hello Message Queue"};

    msgsnd(msgid, &msg, sizeof(msg.mtext), 0);
    printf("Message sent successfully! Check with $ ipcs -q\n");
    return 0;
}