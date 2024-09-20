/*
============================================================================
Name : 20a.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    char *fifoPath = "/tmp/myfifo";
    
    if (mkfifo(fifoPath, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    int fd = open(fifoPath, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char message[] = "Hello from the writer!";
    
    write(fd, message, strlen(message) + 1); 
    close(fd);

    return 0;
}

/*  Output :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_20$ gcc -o 20a 20a.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_20$ gcc -o 20b 20b.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_20$ ./20a

*/
