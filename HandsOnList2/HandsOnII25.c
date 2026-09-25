#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key = ftok(".", 'a');
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct msqid_ds ds;

    msgctl(msgid, IPC_STAT, &ds);
    printf("Access Permissions: %o\n", ds.msg_perm.mode);
    printf("UID: %d, GID: %d\n", ds.msg_perm.uid, ds.msg_perm.gid);
    printf("Time of last msgsnd: %ld\n", ds.msg_stime);
    printf("Time of last msgrcv: %ld\n", ds.msg_rtime);
    printf("Current bytes in queue: %lu\n", ds.__msg_cbytes);
    printf("Number of messages: %lu\n", ds.msg_qnum);
    printf("Max bytes allowed: %lu\n", ds.msg_qbytes);
    printf("PID of last msgsnd: %d, msgrcv: %d\n", ds.msg_lspid, ds.msg_lrpid);
    return 0;
}