#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main( int argc, char *argv[])
{

	getpid();
	
	if (argc < 2) {
		printf("Usage: hang <user|system>\n");
		return 1;
	}

	if (!strcmp(argv[1], "user")){
		while (1);
	}
	else if (!strcmp(argv[1], "system")) {
		sleep (5000);
	}

	return 0;
}

