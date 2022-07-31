#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("%i\n", fork()); // guess... 3
	printf("%i\n", fork());
}