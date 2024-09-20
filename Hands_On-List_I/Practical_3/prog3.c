/*	Raj Kanani
	MT2024074
	Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
	identify all the process related information in the corresponding proc directory.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	const char *filename = "file3.txt";

	int fd = creat(filename, O_CREAT|S_IRWXU);
	if(fd == -1){
		perror("create");
		exit(EXIT_FAILURE);
	}

	printf("File descriptor for '%s' : %d\n", filename, fd);
	return 0;
}

/*	OUTPUT:
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_3$ ./prog3
	File descriptor for 'file3.txt' : 3

*/

