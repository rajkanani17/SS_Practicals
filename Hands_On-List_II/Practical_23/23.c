/*
============================================================================
Name : 23.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a program to print the maximum number of files can be opened within a process and
              size of a pipe (circular buffer).
============================================================================
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdio.h>

void main()
{
    long maxFiles;  
    long sizeOfPipe; 

    char *s = "23_fifo";
    mkfifo(s, S_IRWXU);

    maxFiles = sysconf(_SC_OPEN_MAX);

    printf("Maximum number of files that can be opened is: %ld\n", maxFiles);

    // sizeOfPipe = pathconf(s, _PC_PIPE_BUF); //for size of fifo file 's' buffer

    printf("Maximum size of pipe: %d\n", PIPE_BUF);
    
}
/*  Output:
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_23$ gcc -o 23 23.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_23$ ./23
    Maximum number of files that can be opened is: 1024
    Maximum size of pipe: 4096

*/