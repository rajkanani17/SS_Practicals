/*
============================================================================
Name : 12.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
              the parent process from the child process.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
int main()
{
    int pid;
    pid = fork();
    if (pid == 0)
    {
        printf("inside child pid= %d\n", getpid());
        printf("parent id= %d\n", getppid()); 
        int status=kill(getppid(),SIGKILL);
        if(status==0){
            printf("Parent is killed Chiled is now orphen\n");   
            sleep(10);
        }else{
            perror("Error while killing parent process!");
        }
    }
    else
    {
        while(1);
    }
    return 0;
}
/*  Output:
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_12$ gcc -o 12 12.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_12$ ./12
    inside child pid= 4252
    parent id= 4251
    Parent is killed Chiled is now orphen
    Killed

*/