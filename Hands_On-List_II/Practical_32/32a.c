/*
============================================================================
Name : 32a.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a program to implement semaphore to protect any critical section.
              a. rewrite the ticket number creation program using semaphore
              b. protect shared memory from concurrent write access
              c. protect multiple pseudo resources ( may be two) using counting semaphore   
              d. remove the created semaphore
============================================================================
*/
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
    char *ticketFile = "./ticketFile.txt";

    int fileDescriptor;
    int readBytes, writeBytes;
    int lseekOffset;
    int data;

    int semKey;
    int semIdentifier;
    int semctlStatus; 
    int semopStatus;

    fileDescriptor = open(ticketFile, O_CREAT | O_RDWR, S_IRWXU);
    if (fileDescriptor == -1)
    {
        printf("Error while creating / opening the ticket file!\n");
        exit(0);
    }

    union semun
    {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
        struct seminfo *__buf;
    } semSet;

    semKey = ftok(".", 331);
    if (semKey == -1)
    {
        printf("Error while computing key!\n");
        exit(1);
    }

    semIdentifier = semget(semKey, 1, 0);
    if (semIdentifier == -1)
    {
        semIdentifier = semget(semKey, 1, IPC_CREAT | 0700);
        if (semIdentifier == -1)
        {
            printf("Error while creating semaphore!\n");
            exit(1);
        }

        semSet.val = 1;
        semctlStatus = semctl(semIdentifier, 0, SETVAL, semSet);
        if (semctlStatus == -1)
        {
            printf("Error while initializing a binary sempahore!\n");
            exit(1);
        }
    }

    struct sembuf semOp;
    semOp.sem_num = 0;
    semOp.sem_flg = 0;

    printf("Press enter to obtain lock on the critical section\n");
    getchar();

    semOp.sem_op = -1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        printf("Error while operating on semaphore!\n");
        exit(1);
    }
    
    printf("Obtained lock on critical section!\n");
    printf("Now entering critical section!\n");

    readBytes = read(fileDescriptor, &data, sizeof(data));
    if (readBytes == -1)
    {
        printf("Error while reading from ticket file!\n");
        exit(0);
    }
    else if (readBytes == 0)
        data = 1;
    else
    {
        data += 1;
        lseekOffset = lseek(fileDescriptor, 0, SEEK_SET);
        if (lseekOffset == -1)
        {
            printf("Error while seeking!\n");
            exit(0);
        }
    }

    writeBytes = write(fileDescriptor, &data, sizeof(data));
    if (writeBytes == -1)
    {
        printf("Error while writing to ticket file!\n");
        exit(1);
    }

    printf("Your ticker number is - %d\n", data);

    printf("Press enter to exit from critical section!\n");
    getchar();

    semOp.sem_op = 1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        printf("Error while operating on semaphore!\n");
        exit(1);
    }
    close(fileDescriptor);

    return 0;
}
/*  Output :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_32$ gcc -o 32a 32a.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_32$ ./32a
    Press enter to obtain lock on the critical section

    Obtained lock on critical section!
    Now entering critical section!
    Your ticker number is - 1
    Press enter to exit from critical section!

*/
