/*	Raj Kanani
	MT2024074
	Write a program, call fork and print the parent and child process id.
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	printf("Parent process id = %d\n", getpid());
	int id = fork();
	if(id) printf("Child process id = %d\n", id);
	return 0;
}

/*	OUTPUT :
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_21$ ./prog_21
	Parent process id = 6003
	Child process id = 6004

*/