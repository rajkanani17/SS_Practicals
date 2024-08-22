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
	if(symlink("prog1","softlnkprog1") == -1){
		perror("symlink");
		return 1;
	}
        return 0;
}
