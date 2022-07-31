#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void ChildHandler(int Signal)
{
	system("who");
	kill(getppid(), SIGUSR2);
}

int ChildID;

void ParentHandler(int Signal)
{
	kill(ChildID, SIGKILL);
	sleep(5);
	
	printf("Child executed, exiting\n");
	_exit(0);
}

int main()
{
	ChildID = fork();
	if (!ChildID)
	{
		signal(SIGUSR1, ChildHandler);
		
		printf("Hello there I'm the child\n");
		sleep(100000000);
		sleep(100000000);
		
		return 0;
	}
	
	signal(SIGUSR2, ParentHandler);	
	
	sleep(2);
	
	printf("I'm the parent, and I'll be killing my child\n");
	
	kill(ChildID, SIGUSR1);
	sleep(1000000);
	return 0;
}