#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char buf[1024];
	sprintf(buf, "/usr/bin/xterm -e \"/bin/echo $$; error\" \n", getpid());

	system(buf);
	return 0;
}



