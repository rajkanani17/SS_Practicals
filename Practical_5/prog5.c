/*	Raj Kanani
	MT2024074
	Write a program to create five new files with infinite loop. Execute the program in the background
	and check the file descriptor table at /proc/pid/fd.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int i;
	int fds[5];

	for(i=0; i<5; i++){
		char filename[20];
		snprintf(filename, sizeof(filename), "file_5_%d.txt", i);
		fds[i] = open(filename, O_CREAT | O_RDWR | O_APPEND, 0644);
		if(fds[i] < 0){
			perror("open");
			exit(EXIT_FAILURE);
		}
	}

	while(1){
		sleep(1);
	}

	for(i=0; i<5; i++){
		close(fds[i]);
	}

	return 0;
}
