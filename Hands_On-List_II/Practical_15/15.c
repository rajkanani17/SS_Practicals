/*
============================================================================
Name : 15.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a simple program to send some data from parent to the child process.
============================================================================
*/
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int pipefd[2];
    pid_t cpid;
    char buf;
    char s[10];

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    cpid = fork();
    if (cpid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0)
    { 
        sleep(5);
        close(pipefd[1]); 

        printf("display in child \n");
        while (read(pipefd[0], &buf, 1) > 0)
            write(1, &buf, 1);

        write(1, "\n", 1);
        close(pipefd[0]); 
    }
    else
    { 

        printf("writing in pipe from parent process\n");
        scanf("%s", s);
        close(pipefd[0]); 
        write(pipefd[1], s, strlen(s));
        close(pipefd[1]);
        wait(0);         
    }
}
/*  Output:
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_15$ gcc -o 15 15.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_15$ ./15
    writing in pipe from parent process
    Hello
    display in child 
    Hello

*/