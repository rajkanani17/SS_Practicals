#include<stdio.h>
#include<unistd.h>

int main()
{
	if(symlink("prog1","softlnkprog1") == -1){
		perror("symlink");
		return 1;
	}
        return 0;
}
