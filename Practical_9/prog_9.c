/*	Raj Kanani
	MT2024074
	Write a program to print the following information about a given file.
	a. inode
	b. number of hard links
	c. uid
	d. gid
	e. size
	f. block size
	g. number of blocks
	h. time of last access	
	i. time of last modification
	j. time of last change
*/

#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>
int main(int argv,char *argc[])
{
	struct stat s;
	stat(argc[1], &s);
	printf("id of device=%ld\n",s.st_dev);
	printf("inode = %ld\n",s.st_ino);
	printf("file type and mode = %d\n", s.st_mode);
	printf("number of harldink = %ld\n", s.st_nlink);
	printf("user id = %d\n",s.st_uid);
	printf("group id = %d\n", s.st_gid);
	printf("device id = %ld\n",s.st_rdev);
	printf("total size in bytes = %ld\n",s.st_size);
	printf("Block size of filesystem = %ld\n", s.st_blksize);
	printf("Number of block = %ld\n", s.st_blocks);
	printf("Last access time = %s", ctime(&(s.st_atim).tv_sec));
	printf("Last modified time = %s", ctime(&(s.st_mtim).tv_sec));
	printf("Last status change time = %s", ctime(&(s.st_ctim).tv_sec));
	return 0;
}

/*	OUTPUT :
	kanani-raj@kanani-raj-HP-Laptop-15s-du1xxx:~/Practicals/Practical_9$ ./prog_9 file_9
	id of device=66309
	inode = 6330482
	file type and mode = 33204
	number of harldink = 1
	user id = 1000
	group id = 1000
	device id = 0
	total size in bytes = 0
	Block size of filesystem = 4096
	Number of block = 0
	Last access time = Fri Aug 30 09:46:53 2024
	Last modified time = Fri Aug 30 09:46:53 2024
	Last status change time = Fri Aug 30 09:46:53 2024
*/