/*
============================================================================
Name : 24.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a program to create a message queue and print the key and message queue id.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct mesg_buffer
{
    /* data */
    long mesg_type;
    char mesg_text[100];
} mesg_buffer;
int main()
{
   
    mesg_buffer message;
    
    key_t key = ftok(".", 1); 
    printf("Key for given path and project id is :%d \n", key);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    printf("Message queue id : %d\n", msgid);
    return 0;
}
/*  Output:
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_24$ gcc -o 24 24.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_24$ ./24
    Key for given path and project id is :17126879 
    Message queue id : 0

*/