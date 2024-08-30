/*	Raj Kanani
	MT2024074
	Write a program to create a Zombie state of the running program.
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int f;
	f = fork();
	if(f == 0)
	{
		printf("Inside child pid = %d\n", getpid());
		printf("Parent id = %d\n", getppid());
	}else{
		sleep(300);
		printf("Inside parent pid = %d\n", getpid());
		printf("Child pid = %d\n", f);
	}
	return 0;
}

/*	OUTPUT :
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_23$ ./prog_23
	Inside child pid = 6344
	Parent id = 6343

*/
