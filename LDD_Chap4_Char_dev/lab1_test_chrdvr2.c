#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int length, fd1, fd2, rc;
	char *nodename = "/dev/chardrv";
	char message[] = " RONALD PINA: Testing CHAR drive esting closing device fjsldfkjsdlfjsldfjldskjflkdsjflkdsjflkj ldkfjlskjfldkjf kldjf lskdjfkldsjfklsjd kldjf lkdjflkdjfkldsj lkd fkdjldksjfkldj kldjf kldjfkldjsfkldj kldfjkldsj fdkfjkldsfjlkdjfkldsjfkldsjfkljdklfjdsklfjkldjf kdjf kldjfkldjfkljfkljdklfjldsk jkf kdljfkldsjfkldsfjkldsjfkljdsfkljdsfjsdkljfkldsfjkldjfkldsjfklsdjfkljdfkldsjflksjdflkjdlskfjskldjfkldsjfkldj kfdjskldjfkldsjflkdsjflk 00000000000000000000000000000000";

	length = sizeof(message);

	if (argc > 1)
		nodename = argv[1];

	fd1 = open(nodename, O_RDWR);
	printf(" Opened file descriptor first time: FD#%d\n", fd1);

	fd2 = open(nodename, O_RDWR);
	printf("opened file descriptor second time: FD#%d\n", fd2);

	rc = write(fd1, message, length);
	printf("Return code from write numebr %d on fd#%d\n", rc, fd1);

	memset(message, 0, length);  //fill memory with constant bytes

        rc = read(fd2, message, length);
        printf("Return code from read number %d on fd#%d, message=%s\n", rc, fd2, message);

	close(fd1);
	exit(0);
}

