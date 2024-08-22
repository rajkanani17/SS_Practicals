#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc, char *argv[])
{
	int i = mkfifo(argv[1],S_IRWXU);
	if(i == 0){
		printf("Fifo special file is created successfully\n");
	}
	else{
		printf("Fifo not created");
	}
	return 0;
}
