/*  Raj Kanani
    MT2024074
    Write a program to perform Record locking.
    a. 
    b. Implement read lock
    Create three records in a file. Whenever you access a particular record, first lock it then modify/access
    to avoid race condition.
*/
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int fd = open("/home/kanani-raj/Practicals/Practical_18/file_18.txt", O_RDONLY);
    struct flock rdlock = {F_RDLCK, SEEK_SET, 0, 34, getpid()};
    int id;
    printf("Enter record id:");
    scanf("%d", &id);
    switch (id)
    {
    case 1:
        rdlock.l_start = 0;
        break;
    case 2:
        rdlock.l_start = 17;
        break;
    case 3:
        rdlock.l_start = 34;
        break;
    default:
        perror("invalid choice of record!!!");
        return 0;
    }
    fcntl(fd, F_SETLKW, &rdlock);
    printf("record %d id locked Enter to unlock it\n", id);
    getchar();
    getchar();
    rdlock.l_type = F_ULOCK;
    fcntl(fd, F_SETLKW, &rdlock);
    printf("record is unlocked\n");
    return 0;
}

/*  OUTPUT :
    kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_18$ ./prog_18_b
    Enter record id:3
    record 3 id locked Enter to unlock it

    record is unlocked

*/