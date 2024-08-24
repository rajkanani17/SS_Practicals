/*	Raj Kanani
	MT2024074
	Write a program to display the environmental variable of the user (use environ).
*/
#include<stdio.h>
#include<stdlib.h>
extern char **environ;
int main()
{
	char **e = environ;
	while(*e){
		printf("%s\n", *e);
		e++;
	}
	return 0;
}
