/*  Raj Kanani
    MT2024074
    Write a program to execute ls -Rl by the following system calls
    b. execlp
*/
#include <stdio.h>
#include <unistd.h>
int main()
{
    // it will use environment variable PATH to run executable PATH .
    // it does not required entire file path as we did in execl().
    char *path = "ls";
    execlp(path, path, "-Rl", NULL);
    return 0;
}

/*  OUTPUT :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_27$ ./prog_27_b
    .:
    total 84
    -rwxrwxr-x 1 kanani-raj kanani-raj 15968 Aug 30 10:43 prog_27_a
    -rw-rw-r-- 1 kanani-raj kanani-raj   990 Aug 30 10:44 prog_27_a.c
    -rwxrwxr-x 1 kanani-raj kanani-raj 15968 Aug 30 10:45 prog_27_b
    -rw-rw-r-- 1 kanani-raj kanani-raj   378 Aug 30 10:45 prog_27_b.c
    -rwxrwxr-x 1 kanani-raj kanani-raj 15968 Aug 29 20:02 prog_27_c
    -rw-rw-r-- 1 kanani-raj kanani-raj   225 Aug 29 19:58 prog_27_c.c
    -rwxrwxr-x 1 kanani-raj kanani-raj 16016 Aug 29 20:01 prog_27_d
    -rw-rw-r-- 1 kanani-raj kanani-raj   156 Aug 29 19:52 prog_27_d.c
    -rw-rw-r-- 1 kanani-raj kanani-raj   291 Aug 29 19:54 prog_27_e.c
*/