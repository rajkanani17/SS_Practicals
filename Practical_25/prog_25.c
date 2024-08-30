/*
Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int i,j,k;

	if(!(i = fork()))
	{
		sleep(1);
	}
	else
	{
		if(!(j = fork()))
			sleep(3);
		else
		{
			if(!(k = fork()))
				sleep(10);
			else
				waitpid(j, NULL, 0);
		}
	}
	return 0;
}
