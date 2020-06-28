/*
 * =====================================================================================
 *
 *       Filename:  test_chrdvr2.c
 *
 *    Description:  Test prograp to test the new driver , using open
 *    read etc.
 *
 *        Version:  1.0
 *        Created:  06/28/2020 09:57:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int length, fd1, fd2, rc;
	char *nodename = "/dev/mycdrv";
	char message[] = "Testing CHAR driver";

	length = sizeof(message);

	if (argc > 1)
		nodename = argv[1];

	fd1 = open(nodename, O_RDWR);
	printf("opened file descriptor first ime = %d\n", fd1);

	fd2 = open(nodename, O_RDWR);
	printf("opened file descriptor seconf ime = %d\n", fd2);

	rc = write(fd1, message, length);
	printf("Return code from write=%d on fd#%d\n", rc, fd1);

	memset(message, 0, length); //fill memory with constant bytes

    rc = read(fd2, message, length);
    printf("Return code from read=%d on fd#%d\n", rc, fd2);

	close(fd1);
	return 0;
}

