#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ArgC, const char* const* Args)
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
		char Buffer[32];
		
		sprintf(Buffer, "%i", Num - 1);
		execl(Args[0], Args[0], Buffer, NULL); // would opt for 0, but gcc is being gay so NULL it is
	}
}