/*
============================================================================
Name : 28.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
============================================================================
*/
#include <sys/msg.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <time.h>
typedef struct mesg_buffer
{
    long mesg_type;
    char mesg_text[100];
} mesg_buffer;
int main(int argc, char const *argv[])
{
    mesg_buffer message;
    key_t key = ftok(".", 1); 
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct msqid_ds buf;
    msgctl(msgid, IPC_STAT, &buf);
    struct ipc_perm msg_perm = buf.msg_perm; 
    printf("access permission %d\n", msg_perm.mode);
    buf.msg_perm.mode = 0776;
    msgctl(msgid, IPC_SET, &buf);

    struct msqid_ds cbuf;
    msgctl(msgid, IPC_STAT, &cbuf);
    struct ipc_perm u_msg_perm = cbuf.msg_perm; 
    printf("access permission %d\n", u_msg_perm.mode);
    return 0;
}
/*  Output:
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_28$ gcc -o 28 28.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_28$ ./28
    access permission 438
    access permission 510

*/