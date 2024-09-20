/*
============================================================================
Name : 11.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
              use sigaction system call. 
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
void main()
{
    int status;

    printf("ignoring the SIGINT signal for 5 seconds\n");
    struct sigaction act;

    act.sa_handler = SIG_IGN; 
    act.sa_flags = 0;
    status = sigaction(SIGINT, &act,NULL);
    if (status == -1)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        sleep(5);
    }

    printf("reseting the default action of the SIGINT signal\n");
    struct sigaction actdefault;

    actdefault.sa_handler = SIG_DFL; 
    actdefault.sa_flags = 0;
    status = sigaction(SIGINT, &actdefault,NULL);
    if (status == -1)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        sleep(5);
    }
}
/*  Output:
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_11$ gcc -o 11 11.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_11$ ./11
    ignoring the SIGINT signal for 5 seconds
    reseting the default action of the SIGINT signal

*/