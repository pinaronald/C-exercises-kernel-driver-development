#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int length, fd1, fd2, rc;
	char *nodename = "/dev/chardrv";
	char message[] = "Testing CHAR drive";

	length = sizeof(message);

	if (argc > 1)
		nodename = argv[1];

	fd1 = open(nodename, O_RDWR);
	printf("opened file descriptor first time = %d\n", fd1);

	fd2 = open(nodename, O_RDWR);
	printf("opened file descriptor second time = %d\n", fd2);

	rc = write(fd1, message, length);
	printf("Return code from write=%d on fd#%d\n", rc, fd1);

	memset(message, 0, length);  //fill memory with constant bytes

    rc = read(fd2, message, length);
    printf("Return code from read=%d on fd#%d\n", rc, fd2);

	close(fd1);
	return 0;
}

