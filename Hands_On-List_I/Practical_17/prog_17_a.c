/*	Raj Kanani
	MT2024074
	Write a program to simulate online ticket reservation. Implement write lock
	Write a program to open a file, store a ticket number and exit. Write a separate program, to
	open the file, implement write lock, read the ticket number, increment the number and print
	the new ticket number then close the file.
*/
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc, char *argv[])
{
	printf("Enter ticket number:\n");
	int fd = open(argv[1], O_RDWR | O_CREAT, S_IRWXU);
	if(fd == -1){
		perror("Can't opening file");
		return 0;
	}
	char *b[10];
	int n = read(0, b, 10);
	write(fd, b, n);
	printf("ticket number is stored in file\n");
	return 0;
}

/*	OUTPUT :
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_17$ ./prog_17_a file_17.txt
	Enter ticket number:
	1234
	ticket number is stored in file

*/
