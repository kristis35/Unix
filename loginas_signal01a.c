#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

void AlarmHandler(int Signal)
{
	printf("Alarm received %i\n", Signal);
}

void ChildHandler(int Signal)
{
	int Status;
	int Pid;
		
	Pid = wait(&Status);
	printf("The child %i has noped out with status %i\n", Pid, WEXITSTATUS(Status));
}

int main()
{
	signal(SIGCHLD, ChildHandler);
	signal(SIGALRM, AlarmHandler);
	
	if (!fork())
	{
		printf("It's a me, the child\n");
		kill(getppid(), SIGALRM);
		sleep(1);
		return 0;
	}
	
	sleep(1000); // 1000 seconds of wait time, no it won't wait for 1000 seconds, it'll get signaled and break out, twice
	sleep(1000);
	printf("It's a me, the parent\n");
}