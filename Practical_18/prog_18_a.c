/*  Raj Kanani
    MT2024074
    Write a program to perform Record locking.
    a. Implement write lock
	b.
    Create three records in a file. Whenever you access a particular record, first lock it then modify/access
    to avoid race condition.
*/
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
int main()
{
    int fd = open("/home/kanani-raj/Practicals/Practical_18/file_18.txt", O_RDWR);
    int id, ticket;
    char name[12];
    struct flock rdlock = {F_WRLCK, SEEK_SET, 0, 34, getpid()};
    int i;
    printf("Enter record id:");
    scanf("%d", &i);
    switch (i)
    {
    case 1:
        rdlock.l_start = 0;
        id = 1;
        ticket = 1;
        lseek(fd, 0, SEEK_SET);
        break;
    case 2:
        rdlock.l_start = 17;
        id = 2;
        ticket = 2;
        lseek(fd, 17, SEEK_SET);
        break;
    case 3:
        rdlock.l_start = 34;
        id = 3;
        ticket = 3;
        lseek(fd, 34, SEEK_SET);
        break;
    default:
        perror("invalid choice of record!!!");
        return 0;
    }
    fcntl(fd, F_SETLKW, &rdlock);
    printf("record %d id locked\n", id);
    printf("Enter new ticket no ");
    scanf("%d", &ticket);
    char buf[17];
    sprintf(buf, "id=%dticket_no=%d", id, ticket);
    write(fd, &buf, sizeof(buf));
    getchar();
    rdlock.l_type = F_ULOCK;
    fcntl(fd, F_SETLKW, &rdlock);
    printf("record is unlocked\n");
    return 0;
}

/*	OUTPUT :
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_18$ ./prog_18_a 
	Enter record id:3
	record 3 id locked
	Enter new ticket no 30
	record is unlocked

*/
