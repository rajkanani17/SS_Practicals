/*	Raj Kanani
	MT2024074
	Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
	identify all the process related information in the corresponding proc directory.
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
	const char *filename = "file4.txt";

	int fd = open(filename, O_RDWR);

	if(fd==-1){
		perror("open");
		exit(EXIT_FAILURE);
	}

	printf("File %s opened with read/write permissions. File descriptor : %d\n", filename, fd);

	int fd_excl = open(filename, O_EXCL);

	if(fd_excl == -1){
		perror("open with O_EXCL");
	}
	else{
		printf("File '%s' opened with O_EXCL flag. File descriptor: %d\n", filename,fd_excl);
		close(fd_excl);
	}
	return 0;

}

/*	OUTPUT :
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_4$ ./prog4
	File file4.txt opened with read/write permissions. File descriptor : 3
	File 'file4.txt' opened with O_EXCL flag. File descriptor: 4

*/