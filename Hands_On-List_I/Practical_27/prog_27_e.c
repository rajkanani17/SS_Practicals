/*  Raj Kanani
    MT2024074
    Write a program to execute ls -Rl by the following system calls
    e. execvp
*/
#include <stdio.h>
#include <unistd.h>
int main()
{
    // it will use environment variable PATH to run executable PATH .
    // it does not required entire file path as we did in execl().
    char *path = "ls";
    char *argv[] = {path, "-Rl", NULL};
    execvp(path, argv);
    return 0;
}

/*  OUTPUT :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_27$ ./prog_27_e
    .:
    total 116
    -rwxrwxr-x 1 kanani-raj kanani-raj 15968 Aug 30 10:47 prgo_27_c
    -rwxrwxr-x 1 kanani-raj kanani-raj 15968 Aug 30 10:43 prog_27_a
    -rw-rw-r-- 1 kanani-raj kanani-raj   990 Aug 30 10:44 prog_27_a.c
    -rwxrwxr-x 1 kanani-raj kanani-raj 15968 Aug 30 10:45 prog_27_b
    -rw-rw-r-- 1 kanani-raj kanani-raj  1123 Aug 30 10:46 prog_27_b.c
    -rwxrwxr-x 1 kanani-raj kanani-raj 15968 Aug 29 20:02 prog_27_c
    -rw-rw-r-- 1 kanani-raj kanani-raj   511 Aug 30 10:47 prog_27_c.c
    -rwxrwxr-x 1 kanani-raj kanani-raj 16016 Aug 30 10:48 prog_27_d
    -rw-rw-r-- 1 kanani-raj kanani-raj  1084 Aug 30 10:50 prog_27_d.c
    -rwxrwxr-x 1 kanani-raj kanani-raj 16016 Aug 30 10:51 prog_27_e
    -rw-rw-r-- 1 kanani-raj kanani-raj   427 Aug 30 10:51 prog_27_e.c

*/