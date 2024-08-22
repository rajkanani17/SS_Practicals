/*	Raj Kanani
	MT2024074
	Write a program to copy file1 into file2 ($cp file1 file2).
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	if(argc != 3){
		perror("Invalid parameter");
		return 0;
	}

	FILE *f1 = fopen(argv[1], "r");
	FILE *f2 = fopen(argv[2], "w");

        char c;
	while((c= fgetc(f1)) != EOF){
		fputc(c, f2);
	}
	
	return 0;
}
