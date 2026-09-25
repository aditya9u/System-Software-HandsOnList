#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key = ftok(".", 'a');
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct msqid_ds ds;

    msgctl(msgid, IPC_STAT, &ds);
    ds.msg_perm.mode = 0644;
    if (msgctl(msgid, IPC_SET, &ds) == 0) {
        printf("Permissions changed successfully to 0644!\n");
    }
    return 0;
}