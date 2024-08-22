/* Raj Kanani
   MT2024074
   Create the following types of a files using (i) shell command (ii) system call
	a. soft link (symlink system call)
	b. hard link (link system call)
	c. FIFO (mkfifo Library Function or mknod system call)
*/

#include<stdio.h>
#include<unistd.h>
int main()
{
	char *s = "prog1_b";
	char *d = "hardlnk";
	if(link(s,d) != 0){
		perror("link");
		return 1;
	}
	printf("Hard Link created successfully");
	return 0;
}
