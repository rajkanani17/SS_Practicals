/*
============================================================================
Name : 19e.c
Author : Raj Kanani
Roll No : MT2024074
Description : Create a FIFO file by
              e. mkfifo library function
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
    int ans = mkfifo("fileE", S_IRWXU);

    if(ans == -1)
    {
        printf("Error in creating FIFO file using mkfifo library!\n");
        exit(-1);
    }

    printf("FIFO file created!\n");

	return 0;
}
/*  Output:
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_19$ gcc -o 19e 19e.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_19$ ./19e
    FIFO file created!

*/