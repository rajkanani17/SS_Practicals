/*
============================================================================
Name : 26.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a program to send messages to the message queue. Check $ipcs -q
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
    int messageSendStatus;

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
    data.someNumber = 100;

    messageSendStatus = msgsnd(queueIdentifier, &data, sizeof(data), 0);

    if (messageSendStatus == -1)
    {
        perror("Error while sending message via Message Queue!\n");
        _exit(0);
    }

    printf("Message sent!\n");

    return 0;
}
/*  Output:
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_26$ gcc -o 26 26.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_26$ ./26
    Key: 17126881
    Message Queue Identifier: 0

    Message sent!
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_26$ ipcs -q

    ------ Message Queues --------
    key        msqid      owner      perms      used-bytes   messages    
    0x010555e1 0          kanani-raj 700        16           1   
*/