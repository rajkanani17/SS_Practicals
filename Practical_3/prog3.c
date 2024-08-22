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
	mode_t mode = 0644;

	int fd = creat(filename, mode);
	if(fd == -1){
		perror("create");
		exit(EXIT_FAILURE);
	}

	printf("File descriptor for '%s' : %d\n", filename, fd);

	if(close(fd) == -1){
		perror("close");
		exit(EXIT_FAILURE);
	}

	return 0;

}

