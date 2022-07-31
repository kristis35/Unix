#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int Status;
	
	if (!fork())
	{
		system("ps -f");
		return 0;
	}
	
	wait(&Status);
	return 0;
}