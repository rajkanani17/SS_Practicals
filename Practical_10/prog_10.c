/*	Raj Kanani
	MT2024074
	Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
	bytes (use lseek) and write again 10 bytes.
	a. check the return value of lseek
	b. open the file with od and check the empty spaces in between the data.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argv, char *argc[])
{
	int f = open(argc[1], O_RDWR | O_CREAT, S_IRWXU);
	if (f == -1){
		perror("Can't opening file");
		close(f);
		return 0;
	}
	char s[10] = "ABCDEFGHIJ";
	write(f, s, 10);
	int op = lseek(f, 10, SEEK_CUR);
	printf("%d\n",op);
	write(f,s,10);
	op = lseek(f, 0, SEEK_CUR);
	printf("%d\n",op);
	return 0;
}

/*	OUTPUT :
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_10$ ./prog_10 file_10.txt
	20
	30
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_10$ od -c file_10.txt
	0000000   A   B   C   D   E   F   G   H   I   J  \0  \0  \0  \0  \0  \0
	0000020  \0  \0  \0  \0   A   B   C   D   E   F   G   H   I   J
	0000036

*/
