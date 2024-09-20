/*
============================================================================
Name : 13b.c
Author : Raj Kanani
Roll No : MT2024074
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
              will send the signal (using kill system call). Find out whether the first program is able to catch
              the signal or not.
============================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{		

    int pid;
    printf("Enter PID of process: ");
    scanf("%d", &pid);

    int ans = kill(pid, SIGSTOP);
    if(ans == -1)
    {
        printf("Unable to send SIGNAL to given PID\n");
        exit(-1);
    }
	return 0;
}
/*  Output:
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_13$ gcc 13a.c -o 13a
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_13$ ./13a &
    [1] 5192
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_13$ Hello from program 1 and PID: 5192

    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_13$ gcc 13b.c -o 13b
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_13$ ./13b
    Enter PID of process: 5192

    [1]+  Stopped                  ./13a
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Hands_On-List_II/Practical_13$ cat /proc/5192/status
    Name:	13a
    Umask:	0002
    State:	T (stopped)
    Tgid:	5192
    Ngid:	0
    Pid:	5192
    PPid:	4010
    TracerPid:	0
    Uid:	1000	1000	1000	1000
    Gid:	1000	1000	1000	1000
    FDSize:	256
    Groups:	4 24 27 30 46 100 118 1000 
    NStgid:	5192
    NSpid:	5192
    NSpgid:	5192
    NSsid:	4010

*/