/*	Raj Kanani
	MT2024074
	Write a program to create an orphan process.
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int pid;
	pid = fork();
	if(pid == 0){
		sleep(30);
		printf("\nInside child pid = %d\n", getpid());
		printf("Parent id = %d\n", getppid());
	}else{
		sleep(10);
		printf("Inside parent pid = %d\n", getpid());
		printf("Child pid = %d\n", pid);
	}
	return 0;
}

/*	OUTPUT :
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_24$ ./prog_24
	Inside parent pid = 6485
	Child pid = 6486
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_24$ Inside child pid = 6486
 	Parent id = 1465

*/
