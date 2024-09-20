/*
============================================================================
Name : 32b.c
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
#include<sys/shm.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
    int semKey;
    int semIdentifier;
    int semctlStatus;
    int semopStatus;

    int shmKey;
    int shmIdentifier;
    int shmSize = 20;
    char *shmPointer;

    union semun
    {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
        struct seminfo *__buf;
    } semSet;

    semKey = ftok(".", 3321);
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

        semSet.val = 1; // Set a binary semaphore
        semctlStatus = semctl(semIdentifier, 0, SETVAL, semSet);
        if (semctlStatus == -1)
        {
            printf("Error while initializing a binary sempahore!\n");
            exit(1);
        }
    }

    shmKey = ftok(".", 3322);

    if (shmKey == -1)
    {
        printf("Error while computing key!\n");
        exit(0);
    }

    shmIdentifier = shmget(shmKey, shmSize, IPC_CREAT | 0700);

    if (shmIdentifier == -1)
    {
        printf("Error while getting Shared Memory!\n");
        exit(0);
    }

    shmPointer = shmat(shmIdentifier, (void *)0, 0);

    if (*shmPointer == -1)
    {
        printf("Error while attaching address space!\n");
        exit(0);
    }

    struct sembuf semOp;
    semOp.sem_num = 0;
    semOp.sem_flg = 0;

    printf("Press enter to lock the critical section!\n");
    getchar();
    
    semOp.sem_op = -1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        printf("Error while operating on semaphore!\n");
        exit(1);
    }
    
    printf("Critical Section is now locked!\n");

    printf("Start of the critical section!\n");


    printf("Writing to the shared memory!\n");
    sprintf(shmPointer, "This sentence is written inside shared memory\n");

    printf("Press enter to read from the shared memory!\n");
    getchar();

    printf("%s\n", shmPointer);

    printf("Press enter to exit the critical section!\n");
    getchar();

    semOp.sem_op = 1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        printf("Error while operating on semaphore!\n");
        exit(1);
    }

    printf("Critical section is now unlocked!\n");

    return 0;
}
/*  Output :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_32$ gcc -o 32b 32b.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_32$ ./32b
    Press enter to lock the critical section!

    Critical Section is now locked!
    Start of the critical section!
    Writing to the shared memory!
    Press enter to read from the shared memory!

    This sentence is written inside shared memory

    Press enter to exit the critical section!

    Critical section is now unlocked!

*/