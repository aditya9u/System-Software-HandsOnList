#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct record {
    int id;
    int data;
};

int main() {
    int fd = open("records.db", O_RDWR | O_CREAT, 0666);
    int rec_no = 1; // Access record 2 (0-indexed)

    struct flock fl = {F_WRLCK, SEEK_SET, rec_no * sizeof(struct record), sizeof(struct record), 0};
    fcntl(fd, F_SETLKW, &fl);

    printf("Record %d locked. Performing operations...\n", rec_no);
    sleep(2);

    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &fl);
    close(fd);
    return 0;
}