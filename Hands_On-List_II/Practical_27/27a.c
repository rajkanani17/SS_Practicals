/*
============================================================================
Name : 27a.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a program to receive messages from the message queue.
              a. with 0 as a flag
              b. with IPC_NOWAIT as a flag
============================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    key_t queueKey;
    int queueIdentifier;
    int messageSize;

    struct msgbuf
    {
        long mtype;
        int someNumber;
    } data;

    queueKey = ftok(".", 1);

    if (queueKey == -1)
    {
        perror("Error while computing key!\n");
        _exit(0);
    }

    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);

    if (queueIdentifier == -1)
    {
        perror("Error while creating message queue!\n");
        _exit(0);
    }

    printf("Key: %d\n", queueKey);
    printf("Message Queue Identifier: %d\n\n", queueIdentifier);

    data.mtype = 1;
    data.someNumber = 1;

    messageSize = msgrcv(queueIdentifier, &data, sizeof(data), data.mtype, 0);

    if (messageSize == -1)
    {
        perror("Error while sending message via Message Queue!\n");
        _exit(0);
    }

    printf("Received number: %d\n", data.someNumber);

    return 0;
}
/*  Output:
    ========================== Enter message using Practical 26 ===============================
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_27$ ./26
    Key: 17126882
    Message Queue Identifier: 1

    Message sent!
    ========================== Receiving Message using Practical 27 ============================ 
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_27$ ./27a
    Key: 17126882
    Message Queue Identifier: 1

    Received number: 100

*/