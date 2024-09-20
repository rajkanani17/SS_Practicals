/*
============================================================================
Name : 9.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
              signal - Use signal system call.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
void main()
{
    __sighandler_t status;

    printf("ignoring the SIGINT signal for 5 seconds\n");
    status=signal(SIGINT, SIG_IGN);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        sleep(5); 
    }

    printf("reseting the default action of the SIGINT signal\n");
    status = signal(SIGINT, SIG_DFL);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        sleep(5); 
    }
}
/*  Output:
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_9$ gcc -o 9 9.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_9$ ./9
    ignoring the SIGINT signal for 5 seconds
    reseting the default action of the SIGINT signal

*/