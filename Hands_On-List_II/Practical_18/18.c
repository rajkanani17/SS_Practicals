/*
============================================================================
Name : 18.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write a program to find out total number of directories on the pwd.
              execute ls -l | grep ^d | wc ? Use only dup2.
============================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{	
    int pipeCmdOneToTwo[2], pipeCmdTwoToThree[2];
    int pipeOneStatus, pipeTwoStatus;

    pid_t childOne, childTwo;

    pipeOneStatus = pipe(pipeCmdOneToTwo);
    pipeTwoStatus = pipe(pipeCmdTwoToThree);

    if (pipeOneStatus == -1 || pipeTwoStatus)
        perror("Error while creating the pipe!\n");
    else
    {
        childOne = fork();

        if (childOne == -1)
            perror("Error while creating first child!\n");
        else if (childOne == 0)
        {
            close(pipeCmdTwoToThree[1]);
            close(pipeCmdOneToTwo[0]);
            close(pipeCmdOneToTwo[1]);

            close(STDIN_FILENO);
            dup2(pipeCmdTwoToThree[0], STDIN_FILENO);

            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            childTwo = fork();

            if (childTwo == -1)
                perror("Error while creating second child!\n");
            else if (childTwo == 0)
            {
                close(pipeCmdOneToTwo[1]);
                close(pipeCmdTwoToThree[0]);

                close(STDIN_FILENO);
                dup2(pipeCmdOneToTwo[0], STDIN_FILENO);
                close(STDOUT_FILENO);
                dup2(pipeCmdTwoToThree[1], STDOUT_FILENO);

                execl("/usr/bin/grep", "grep ^d", "^d", NULL);
            }
            else
            {
                close(pipeCmdOneToTwo[0]);
                close(pipeCmdTwoToThree[1]);
                close(pipeCmdTwoToThree[0]);

                close(STDOUT_FILENO);
                dup2(pipeCmdOneToTwo[1], STDOUT_FILENO);

                execl("/usr/bin/ls", "ls -l", "-l", NULL);
            }
        }
    }
}
/*  Output:
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_18$ gcc -o 18 18.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_18$ ./18
          0       0       0
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_18$ ls -l
    total 20
    -rwxrwxr-x 1 kanani-raj kanani-raj 16216 Sep 20 15:28 18
    -rw-rw-r-- 1 kanani-raj kanani-raj  2117 Sep 20 11:58 18.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_18$ mkdir temp
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_18$ ./18
          1       9      59
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_18$ ls -l
    total 24
    -rwxrwxr-x 1 kanani-raj kanani-raj 16216 Sep 20 15:28 18
    -rw-rw-r-- 1 kanani-raj kanani-raj  2117 Sep 20 11:58 18.c
    drwxrwxr-x 2 kanani-raj kanani-raj  4096 Sep 20 15:28 temp
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_18$ ls -l | grep ^d | wc
          1       9      59

*/