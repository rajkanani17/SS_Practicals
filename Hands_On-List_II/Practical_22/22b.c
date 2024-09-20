/*
============================================================================
Name : 22b.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
              system call with FIFO.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int f;
    char *s = "FIFO22";
    mkfifo(s, S_IRWXU);
    f = open(s, O_NONBLOCK | O_WRONLY);

    if (f == -1)
    {
        perror("Error while opening FIFO file!");
        _exit(0);
    }
    char *st;
    long int size=100;
    printf("enter message\n");
    int l=getline(&st,&size,stdin);
    write(f, st, l);
    close(f);
}
/*  Output :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_22$ ./22b
    enter message
    Hello

*/