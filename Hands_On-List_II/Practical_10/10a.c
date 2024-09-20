/*
============================================================================
Name : 10a.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a separate program using sigaction system call to catch the following signals.
              a. SIGSEGV
              b. SIGINT
              c. SIGFPE  
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void print(){
    printf("Caught SIGSEGV\n");
}
void main()
{
    int status;
    struct sigaction act;
    
    act.sa_handler=print;
    act.sa_flags=0;
    status = sigaction(SIGSEGV,&act,NULL);
    if (status == -1)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        raise(SIGSEGV);
    }
}
/*  Output:
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_10$ gcc -o 10a 10a.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_10$ ./10a
    Caught SIGSEGV
*/