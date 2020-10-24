#include <fcntl.h>

#define fourGB 4000000000


int main()
{
	int fd=open("myFile.txt",O_RDWR|O_CREAT,0666);

	if(fd<0)
	 return 1;
	
	if(posix_fallocate(fd,0,fourGB)!=0)
	  return 1;

	return 0;

}


