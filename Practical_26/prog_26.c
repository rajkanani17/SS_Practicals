/*  Raj Kanani
    MT2024074
    Write a program to execute an executable program.
    a. use some executable program
    b. pass some input to an executable program. (for example execute an executable of $./a.out name)
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *executable = "./a.out";
    char *arg1 = "This string is passed as value";         
    char *args[] = {executable, arg1, NULL};

    if (execvp(executable, args) == -1) {
        perror("Error in executing the program");
        exit(EXIT_FAILURE);
    }
    return 0;
}

/*  OUTPUT :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_26$ ./prog_26
    passing value as string

*/