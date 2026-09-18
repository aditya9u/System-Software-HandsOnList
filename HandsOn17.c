#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd = open("ticket_db.txt", O_RDWR | O_CREAT, 0666);
    struct flock fl = {F_WRLCK, SEEK_SET, 0, 0, 0};
    int ticket_no = 0;

    fcntl(fd, F_SETLKW, &fl);
    read(fd, &ticket_no, sizeof(ticket_no));
    ticket_no++;
    lseek(fd, 0, SEEK_SET);
    write(fd, &ticket_no, sizeof(ticket_no));
    printf("Booked Ticket No: %d\n", ticket_no);

    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &fl);
    close(fd);
    return 0;
}