/*	Raj Kanani
	MT2024074
	Write a program to perform mandatory locking.
	a. Implement write lock
	b. Implement read lock
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argv, char *argc[])
{
    int fd = open(argc[1], O_WRONLY);
    if (fd == -1)
    {
        printf("Error while opening file");
    }
    struct flock lock = {F_WRLCK,0,0,0,0}; 
    fcntl(fd, F_SETLKW, &lock);
    printf("File is locked.\npress enter to unlock file\n");
    getchar();
    lock.l_type = F_UNLCK; 
    fcntl(fd, F_SETLKW, &lock);
    return 0; 
}

/*  OUTPUT :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_16$ ./prog_16_a file_16.txt
    File is locked.
    press enter to unlock file

*/