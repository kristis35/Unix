#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int ArgC, char* const* Args)
{
	if (ArgC <= 1)
	{
		printf("Provide at least 1 argument\n");
		return 1;
	}
	
	int Num;
	
	printf("Hello I'm %s pid: %u ppid: %u\n", Args[1], getpid(), getppid());
	
	Num = atoi(Args[1]);
	if (Num > 0)
	{
		char* Arguments[3];
		char Buffer[32];
		
		sprintf(Buffer, "%i", Num - 1);
		
		Arguments[0] = Args[0];
		Arguments[1] = Buffer;
		Arguments[2] = 0;
		
		execvp(Args[0], Arguments);
	}
}