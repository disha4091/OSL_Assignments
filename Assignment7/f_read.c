// Name: Disha Chavan
// Class: TE 10
// Batch: L 10
// Roll No: 33212

#include<stdio.h>
#include<sys/stat.h>

#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

#define MAX_BUF 1024 
int main()
{
	int fd,retval;
	char buffer[MAX_BUF];
	int words =0, chars=0, lines=0;			// initializing count variables

	fd=open("/tmp/myfifo",O_RDONLY);			// Open FIFO for read only

	read(fd,buffer,sizeof(buffer));			// read file into the buffer
	printf("\nThe contents of file are %s\n",buffer);
	int i=0;
	while(buffer[i] != '\0')				// traversing buffer array
	{
	  if(buffer[i] == ' ' || buffer[i] == '\n')
	  {	
	  	words++;
	  }
	  else
	  {
	  	chars++;
	  }
	  if(buffer[i] == '\n')
	  {
	  	lines++;
	  }
	  i++; 
	}
	printf("\n No of Words: %d",words);
	printf("\n No of Characters: %d",chars);
	printf("\n No of Lines: %d\n",lines+1);
	close(fd);						// close fifo
	return 0;
}
