/*
============================================================================
Name : 6.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a simple program to create three threads.
============================================================================
*/
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void print()
{
    printf("Printing from thread\n");
}

void main()
{
    pthread_t threadID1, threadID2, threadID3;
    int pstatus;
    pstatus = pthread_create(&threadID1, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pstatus = pthread_create(&threadID2, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pstatus = pthread_create(&threadID2, NULL, (void *)print, NULL);
    if (pstatus != 0)
    {
        perror("Error while creating thread");
        _exit(1);
    }

    pthread_exit(NULL);
}
/*  Output:
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_6$ gcc -o 6 6.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_6$ ./6
    Printing from thread
    Printing from thread
    Printing from thread

*/