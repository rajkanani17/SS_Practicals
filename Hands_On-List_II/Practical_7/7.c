/*
============================================================================
Name : 7.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a simple program to print the created thread ids.
============================================================================
*/
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void print()
{
    printf("Printing from thread :%lu\n", pthread_self());
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
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_7$ gcc -o 7 7.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_7$ ./7
    Printing from thread :139900787619520
    Printing from thread :139900779226816
    Printing from thread :139900770834112

*/