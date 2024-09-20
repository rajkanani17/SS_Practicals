/*
============================================================================
Name : 8e.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a separate program using signal system call to catch the following signals.
              a. SIGSEGV
              b. SIGINT
              c. SIGFPE
              d. SIGALRM (use alarm system call)
              e. SIGALRM (use setitimer system call)
              f. SIGVTALRM (use setitimer system call)
              g. SIGPROF (use setitimer system call)
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
void print()
{
    printf("SIGALRM caught\n");
    _exit(0);
}

void main()
{
    __sighandler_t status;
    struct itimerval timer;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_sec = 2; 
    timer.it_value.tv_usec = 0;
    int timerStatus = setitimer(ITIMER_REAL, &timer, 0);
    if (timerStatus == -1)
        perror("Error while setting an interval timer!");
    status = signal(SIGALRM, (void *)print);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        while (1);
    }
}
/*  Output:
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_8$ gcc -o 8e 8e.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_8$ ./8e
    SIGALRM caught

*/