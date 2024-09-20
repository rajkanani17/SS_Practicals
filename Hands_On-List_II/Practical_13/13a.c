/*
============================================================================
Name : 13a.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
              will send the signal (using kill system call). Find out whether the first program is able to catch
              the signal or not.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main()
{		

    printf("Hello from program 1 and PID: %d\n", getpid());

    for(;;);

	return 0;
}
