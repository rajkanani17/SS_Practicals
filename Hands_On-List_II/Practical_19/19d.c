/*
============================================================================
Name : 19d.c
Author : Raj Kanani
Roll No : MT2024074
Description : Create a FIFO file by
              d. mknod system call
============================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{		
    int ans = mknod("fileD", S_IFIFO, 0);

    if(ans == -1)
    {
        printf("Error in creating FIFO file using mknod() sys call!\n");
        exit(-1);
    }

    printf("FIFO file created!\n");

	return 0;
}

/*  Output :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_19$ gcc -o 19d 19d.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_19$ ./19d
    FIFO file created!

*/