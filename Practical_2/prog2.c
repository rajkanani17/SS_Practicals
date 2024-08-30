/* Raj Kanani
   MT2024074
   Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
   identify all the process related information in the corresponding proc directory.
*/

#include<stdio.h>
int main()
{
	for(;;){

	}
	return 0;
}

/*	OUTPUT :
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_2$ ./prog2 &
	[5] 9732
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_2$ cat /proc/9732/status
	Name:	prog2
	Umask:	0002
	State:	R (running)
	Tgid:	9732
	Ngid:	0
	Pid:	9732
	PPid:	3174

*/
