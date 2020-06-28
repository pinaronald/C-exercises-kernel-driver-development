#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

int main()
{
	alarm(3);
	sleep(5);
	return 0;
}

