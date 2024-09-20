/*	Raj Kanani
	MT2024074
	Write a program, open a file, call fork, and then write to the file by both the child as well as the
	parent processes. Check output of the file.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main() {

    int fd = open("file_22.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);

    int pid = fork();

    if (pid == 0) {
        const char *child_text = "Child process writing to file.\n";
        if (write(fd, child_text, strlen(child_text)) < 0) {
            perror("Child failed to write to the file");
            close(fd);
            exit(1);
        }
    } else {
        const char *parent_text = "Parent process writing to file.\n";
        if (write(fd, parent_text, strlen(parent_text)) < 0) {
            perror("Parent failed to write to the file");
            close(fd);
            return 1;
        }
        wait(NULL);
	int fd_check = open("file_22.txt", O_RDONLY);
	char buffer[1024];
	read(fd_check, buffer, sizeof(buffer) -1);
	printf("File content:\n%s", buffer);
	close(fd_check);
    }

    close(fd);
    return 0;
}

/*	OUTPUT :
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_22$ ./prog_22
	File content:
	Parent process writing to file.
	Child process writing to file.
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_22$ cat file_22.txt
	Parent process writing to file.
	Child process writing to file.

*/