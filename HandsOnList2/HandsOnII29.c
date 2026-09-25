#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key = ftok(".", 'a');
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgctl(msgid, IPC_RMID, NULL) == 0) {
        printf("Message Queue removed successfully.\n");
    }
    return 0;
}