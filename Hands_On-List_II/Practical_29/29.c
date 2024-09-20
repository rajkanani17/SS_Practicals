/*
============================================================================
Name : 29.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a program to remove the message queue.
============================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include<stdlib.h>

int main()
{
    key_t queueKey;
    int queueIdentifier;
    int msgctlStatus;

    queueKey = ftok(".", 1);

    if (queueKey == -1)
    {
        printf("Error while computing key!\n");
        exit(0);
    }

    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);
    if (queueIdentifier == -1)
    {
        printf("Error while creating Message Queue!\n");
        exit(0);
    }

    printf("Message Queue Identifier: %d\n", queueIdentifier);

    msgctlStatus = msgctl(queueIdentifier, IPC_RMID, NULL);

    if (msgctlStatus == -1)
    {
        printf("Error while removing Message Queue\n");
        exit(0);
    }

    printf("Message Queue Removed\n");

    return 0;
}
/*  Output :
    ============================ Enter message by Practical 26 ================================
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_29$ ./26
    Key: 17126884
    Message Queue Identifier: 1

    Message sent!
    ============================ Remove message by Practical 29 ===============================
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_29$ ./29
    Message Queue Identifier: 1
    Message Queue Removed

*/
