/*	Raj Kanani
	MT2024074
	Find out the priority of your running program. Modify the priority with nice command.
*/
#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include<sys/resource.h>
int main()
{
	int i;
	scanf("%d", &i);
	printf("nice value = %d\n", getpriority(PRIO_PROCESS, i));
	printf("priority = %d\n", (20+getpriority(PRIO_PROCESS, i)));
	return 0;
}

/*	OUTPUT :
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_20$ ./prog_20
	1
	nice value = 0
	priority = 20

*/