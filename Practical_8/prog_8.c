/*	Raj Kanani
	MT2024074
	Write a program to open a file in read only mode, read line by line and display each line as it is read.
	Close the file when end of file is reached.
*/

#include<stdio.h>
int main()
{
	char *f = "file_8";
	FILE *file = fopen(f, "r");
	
	if(file == NULL){
		perror("Can't open the file");
		return 1;
	}

	char l[256];

	while(fgets(l,sizeof(l), file) != NULL){
		printf("%s", l);
	}

	fclose(file);

	return 0;
}
