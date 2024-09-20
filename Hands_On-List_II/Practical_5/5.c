/*
============================================================================
Name : 5.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a program to print the system limitation of
              a. maximum length of the arguments to the exec family of functions.
              b. maximum number of simultaneous process per user id.
              c. number of clock ticks (jiffy) per second.
              d. maximum number of open files
              e. size of a page
              f. total number of pages in the physical memory
              g. number of currently available pages in the physical memory.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
void main()
{
    long val;
    val=sysconf(_SC_ARG_MAX);
    printf("Maximum length of the arguments to the exec family of functions -%ld\n", val);

    val = sysconf(_SC_CHILD_MAX);
    printf("Maximum number of simultaneous process per user id -%ld\n", val);

    val = sysconf(_SC_CLK_TCK);
    printf("Number of clock ticks (jiffy) per second -%ld\n", val);

    val = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of open files -%ld\n", val);

    val = sysconf(_SC_PAGESIZE);
    printf("Size of a page -%ld bytes\n", val);

    val = sysconf(_SC_PHYS_PAGES);
    printf("Total number of pages in the physical memory -%ld\n", val);

    val = sysconf(_SC_AVPHYS_PAGES);
    printf("Number of  currently available pages in the physical memory -%ld\n", val);
}
/*  Output:
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_5$ gcc -o 5 5.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_5$ ./5
    Maximum length of the arguments to the exec family of functions -2097152
    Maximum number of simultaneous process per user id -30652
    Number of clock ticks (jiffy) per second -100
    Maximum number of open files -1024
    Size of a page -4096 bytes
    Total number of pages in the physical memory -1980464
    Number of  currently available pages in the physical memory -982247

*/