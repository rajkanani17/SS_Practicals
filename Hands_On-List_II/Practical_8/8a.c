/*
============================================================================
Name : 8a.c
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
void print()
{
    printf("SIGSEGV caught\n");
    _exit(0);
}

void main()
{
    __sighandler_t status;

    status = signal(SIGSEGV, (void *)print);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        raise(SIGSEGV); 
    }
}
/*  Output:
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_8$ gcc -o 8a 8a.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_8$ ./8a
    SIGSEGV caught
*/