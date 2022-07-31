#include <unistd.h>

int main()
{
	if (!fork())
		fork();
	
	return 0;
}