/*  Raj Kanani
    MT2024074
    Write a program to execute ls -Rl by the following system calls
    c. execle
*/
#include <stdio.h>
#include <unistd.h>
int main(int argc,char *argv[],char *env[])
{
    //we have to pass environment variable
    char *path = "/bin/ls";
    execle(path, path, "-Rl" ,"prog_27_c",NULL, env);
    return 0;
}

/*  OUTPUT :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_27$ ./prog_27_c
    -rwxrwxr-x 1 kanani-raj kanani-raj 15968 Aug 29 20:02 prog_27_c

*/