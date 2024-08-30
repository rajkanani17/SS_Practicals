/*	Raj Kanani
	MT2024074
	Write a program to create five new files with infinite loop. Execute the program in the background
	and check the file descriptor table at /proc/pid/fd.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv)
{
	int f1 = creat("file1", S_IRWXU);
	int f2 = creat("file2", S_IRWXU);
	int f3 = creat("file3", S_IRWXU);
	int f4 = creat("file4", S_IRWXU);
	int f5 = creat("file5", S_IRWXU);
	
	for(;;){}

	return 0;
}

/*	OUTPUT :
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_5$ ./prog5 &
	[1] 3502
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_5$ ls -l /proc/3502/fd
	total 0
	lrwx------ 1 kanani-raj kanani-raj 64 Aug 30 15:20 0 -> /dev/pts/1
	lrwx------ 1 kanani-raj kanani-raj 64 Aug 30 15:20 1 -> /dev/pts/1
	lrwx------ 1 kanani-raj kanani-raj 64 Aug 30 15:20 2 -> /dev/pts/1
	l-wx------ 1 kanani-raj kanani-raj 64 Aug 30 15:20 3 -> /home/kanani-raj/Practicals/Practical_5/file1
	l-wx------ 1 kanani-raj kanani-raj 64 Aug 30 15:20 4 -> /home/kanani-raj/Practicals/Practical_5/file2
	l-wx------ 1 kanani-raj kanani-raj 64 Aug 30 15:20 5 -> /home/kanani-raj/Practicals/Practical_5/file3
	l-wx------ 1 kanani-raj kanani-raj 64 Aug 30 15:20 6 -> /home/kanani-raj/Practicals/Practical_5/file4
	l-wx------ 1 kanani-raj kanani-raj 64 Aug 30 15:20 7 -> /home/kanani-raj/Practicals/Practical_5/file5

*/
