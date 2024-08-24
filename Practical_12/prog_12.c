/*	Raj Kanani
	MT2024074
	Write a program to find out the opening mode of a file. Use fcntl.
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void check_file_mode(int fd) {
    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl");
        return;
    }

    switch (flags & O_ACCMODE) {
        case O_RDONLY:
            printf("File is opened in read-only mode.\n");
            break;
        case O_WRONLY:
            printf("File is opened in write-only mode.\n");
            break;
        case O_RDWR:
            printf("File is opened in read-write mode.\n");
            break;
        default:
            printf("Unknown file mode.\n");
            break;
    }
}

int main(int argv,char *argc[]) {
    int fd = open(argc[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    check_file_mode(fd);
    close(fd);
    return 0;
}
