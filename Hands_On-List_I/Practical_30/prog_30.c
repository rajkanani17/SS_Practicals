/*  Raj Kanani
    MT2024074
    Write a program to run a script at a specific time using a Daemon process.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int main(int argc, char *argv[])
{
    time_t curr, dead;
    struct tm *deadline;

    time(&curr); 
    deadline = localtime(&curr);

    deadline->tm_hour = atoi(argv[1]);
    deadline->tm_min = argv[2] == NULL ? 0 : atoi(argv[2]);
    deadline->tm_sec = argv[3] == NULL ? 0 : atoi(argv[3]);

    dead = mktime(deadline); 

    int cid = fork();
    if (cid == 0)
    {
        setsid();
        do
        {
            time(&curr); 
        } while (difftime(dead, curr) > 0);
        system("echo Current user=$USER");
    }
    else
    {
        exit(0);
    }
}

/*  OUTPUT :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_30$ ./prog_30 file_30.txt
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_30$ Current user=kanani-raj

*/
