/*
============================================================================
Name : 21b.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
============================================================================
*/
#// program2.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO1 "/tmp/fifo1" 
#define FIFO2 "/tmp/fifo2" 

int main() {
    char writeMessage[100], readMessage[100];

    while (1) {
        int fd1 = open(FIFO1, O_RDONLY);
        read(fd1, readMessage, sizeof(readMessage));
        printf("Program 21_a: %s", readMessage);
        close(fd1);

        printf("Program 21_b: Enter message: ");
        fgets(writeMessage, sizeof(writeMessage), stdin);

        int fd2 = open(FIFO2, O_WRONLY);
        write(fd2, writeMessage, strlen(writeMessage) + 1);
        close(fd2);
    }
    return 0;
}
/*  Output :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_21$ ./21b
    Program 21_a: hello
    Program 21_b: Enter message: bye

*/