/*	Raj Kanani
	MT2024074
	Write a program to simulate online ticket reservation. Implement write lock
	Write a program to open a file, store a ticket number and exit. Write a separate program, to
	open the file, implement write lock, read the ticket number, increment the number and print
	the new ticket number then close the file.
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	int fd = open("/home/kanani-raj/Practicals/Practical_17/file_17.txt", O_RDWR);
	struct flock l = {F_WRLCK, SEEK_SET, 0, 0, 0};
	fcntl(fd, F_SETLKW, &l);
	printf("File is locked\n");
	char b[10];
	int n = read(fd, &b, 10);
	int b_int = atoi(b);
	b_int = b_int + 1;
	lseek(fd, 0, SEEK_SET);
	write(fd, &b, strlen(b));
	printf("%d\n",b_int);
	getchar();
	l.l_type = F_UNLCK;
	fcntl(fd, F_SETLKW, &l);
	printf("File is unlocked\n");
	return 0;
}

/*	OUTPUT :
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_17$ ./prog_17_b file_17.txt
	File is locked
	1235

	File is unlocked

*/
