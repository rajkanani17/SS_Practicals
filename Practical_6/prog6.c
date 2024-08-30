/*	Raj Kanani
	MT2024074
	Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#define BUFFER_SIZE 1024
int main()
{
	char buffer[BUFFER_SIZE];
	ssize_t bytesRead;

	while((bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0){
		if(write(STDOUT_FILENO, buffer, bytesRead) != bytesRead) {
			perror("write");
			exit(EXIT_FAILURE);
		}
	}

	if(bytesRead < 0){
		perror("read");
		exit(EXIT_FAILURE);
	}

	return 0;
}

/*	OUTPUT :
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_6$ ./prog6
	Hi, How are you ?
	Hi, How are you ?


	I am fine.
	I am fine.
*/
