/*
============================================================================
Name : 20b.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    char *fifoPath = "/tmp/myfifo";

    int fd = open(fifoPath, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char buffer[100];

    read(fd, buffer, sizeof(buffer));

    printf("Received message: %s\n", buffer);

    close(fd);

    unlink(fifoPath);

    return 0;
}
/*  Output :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_20$ ./20b
    Received message: Hello from the writer!

*/
