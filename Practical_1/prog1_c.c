/* Raj Kanani
   MT2024074
   Create the following types of a files using (i) shell command (ii) system call
   	a. soft link (symlink system call)
   	b. hard link (link system call)
   	c. FIFO (mkfifo Library Function or mknod system call)
*/

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc, char *argv[])
{
	int i = mkfifo(argv[1],S_IRWXU);
	if(i == 0){
		printf("Fifo special file is created successfully\n");
	}
	else{
		printf("Fifo not created");
	}
	return 0;
}

/*	OUTPUT:
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_1$ ./prog1_c fifofile
	Fifo special file is created successfully

*/
