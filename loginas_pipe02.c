#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int ArgC, const char* const* Args)
{
	struct stat Status;
	
	int PipePair[2];
	void* Buffer;
	
	if (ArgC <= 1)
	{
		printf("Missing arguments\n");
		return 0;
	}
	
	stat(Args[1], &Status);
	
	
	pipe(PipePair);
	if (!fork())
	{
		Buffer = malloc(Status.st_size);
		read(PipePair[0], Buffer, Status.st_size);
		
		printf("Done reading pipe, control byte: %X\n", *(((unsigned char*)Buffer) + Status.st_size - 1));
		
		close(PipePair[0]);
		free(Buffer);
		return 0;
	}
	
	int FileDesc;
		
	FileDesc = open(Args[1], O_RDONLY);
	Buffer = malloc(Status.st_size);
		
	read(FileDesc, Buffer, Status.st_size);
		
	close(FileDesc);
	
	printf("Writing to pipe, control byte: %X\n", *(((unsigned char*)Buffer) + Status.st_size - 1));
	
	write(PipePair[1], Buffer, Status.st_size);
	
	close(PipePair[1]);
	free(Buffer);
	
	wait(0);
}