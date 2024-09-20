/* Raj Kanani
   MT2024074
   Create the following types of a files using (i) shell command (ii) system call
	a. soft link (symlink system call)
	b. hard link (link system call)
	c. FIFO (mkfifo Library Function or mknod system call)
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
    if (link("prog_b", "hardlinkfile1") == -1) {
        perror("link");
        return 1;
    }
	else{
		printf("Hard link created successfully");
	}
    return 0;
}

/*	OUTPUT :
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_1$ ./prog1_b
	Hard link created successfully

*/
