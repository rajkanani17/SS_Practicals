/*
============================================================================
Name : 21a.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO1 "/tmp/fifo1" 
#define FIFO2 "/tmp/fifo2"

int main() {
    if (mkfifo(FIFO1, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
    if (mkfifo(FIFO2, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    char writeMessage[100], readMessage[100];

    while (1) {
        printf("Program 21_a: Enter message: ");
        fgets(writeMessage, sizeof(writeMessage), stdin);

        int fd1 = open(FIFO1, O_WRONLY);
        write(fd1, writeMessage, strlen(writeMessage) + 1);
        close(fd1);

        int fd2 = open(FIFO2, O_RDONLY);
        read(fd2, readMessage, sizeof(readMessage));
        printf("Program 21_b: %s", readMessage);
        close(fd2);
    }

    return 0;
}
/*  Output :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_21$ gcc -o 21a 21a.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_21$ gcc -o 21b 21b.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_21$ ./21a
    Program 21_a: Enter message: hello
    Program 21_b: bye

*/