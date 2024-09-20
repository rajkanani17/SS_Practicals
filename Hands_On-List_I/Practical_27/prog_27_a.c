/*  Raj Kanani
    MT2024074
    Write a program to execute ls -Rl by the following system calls
    a. execl
*/
#include <stdio.h>
#include <unistd.h>
int main()
{
    char *path = "/bin/ls";
    execl(path, path, "-Rl", NULL);
    return 0;
}

/*  OUTPUT :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_27$ ./prog_27_a
    .:
    total 84
    -rwxrwxr-x 1 kanani-raj kanani-raj 15968 Aug 30 10:43 prog_27_a
    -rw-rw-r-- 1 kanani-raj kanani-raj   244 Aug 30 10:43 prog_27_a.c
    -rwxrwxr-x 1 kanani-raj kanani-raj 15968 Aug 29 19:56 prog_27_b
    -rw-rw-r-- 1 kanani-raj kanani-raj   264 Aug 29 19:51 prog_27_b.c
    -rwxrwxr-x 1 kanani-raj kanani-raj 15968 Aug 29 20:02 prog_27_c
    -rw-rw-r-- 1 kanani-raj kanani-raj   225 Aug 29 19:58 prog_27_c.c
    -rwxrwxr-x 1 kanani-raj kanani-raj 16016 Aug 29 20:01 prog_27_d
    -rw-rw-r-- 1 kanani-raj kanani-raj   156 Aug 29 19:52 prog_27_d.c
    -rw-rw-r-- 1 kanani-raj kanani-raj   291 Aug 29 19:54 prog_27_e.c

*/