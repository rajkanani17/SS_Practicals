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
	if(symlink("f1","softlink") == -1){
		perror("symlink");
		return 1;
	}
    else{
        printf("Soft linked created Successfully\n");
    }
    return 0;
}

/*  OUTPUT :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_1$ gcc -o prog1_a prog1_a.c
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_1$ ./prog1_a
    Soft linked created Successfully

*/

