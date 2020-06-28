#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int foo = 1;

	printf("my pid = %d\n", getpid());
	pause();
	
	printf("got signal, resuming!\n");

	return (0);
}


