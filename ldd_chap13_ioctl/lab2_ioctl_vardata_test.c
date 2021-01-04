/*
 *
 *       Filename:  lab2_ioctl_vardata_test.c
 *
 *    Description:  Using ioctl to pass data of variable length. User
 *    space app. 
 *
 *        Created:  01/03/2021 09:25:24 PM
 *
 *         Author:  Ronald Pina, rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <malloc.h>
#include <string.h>

#define MYIOC_TYPE 'k'
#define MY_IOW(type,nr,size) _IOC(_IOC_WRITE,(type),(nr),size)
#define MY_IOR(type,nr,size) _IOC(_IOC_READ,(type),(nr),size)

int main(int argc, char *argv[])
{
	int fd, rc, i, lbuf;
	char *buffer, *nodename = "/dev/mycdrv";
	int MYIOC_X;

	/* open the device node */
	if (argc > 1)
		nodename = argv[1];
	fd = open(nodename, O_RDWR);
	printf(" I opened the device node, file descriptor = %d\n", fd);

	/* how big should the buffer be? */
	lbuf = 1000;
	if (argc > 2)
		lbuf = atoi(argv[1]);
	printf(" I am going to send back a buffer of %d bytes\n", lbuf);

	/* malloc the buffer */
	buffer = malloc(lbuf);

	/* send the IOCTL and read the contents from the kernel */
	printf("\n	*** Getting data from the kernel: ***\n");
	MYIOC_X = (int)MY_IOR(MYIOC_TYPE, 1, lbuf);
	rc = ioctl(fd, MYIOC_X, buffer);
	printf("\n rc from ioctl = %s \n\n", rc);

	printf(" buffer in user-space is =\n	");
	for (i = 0; i < lbuf; i++)
		printf("%c", buffer[i]);
	printf("\n");

	/* clear it and send it back */
	memset(buffer, '0', lbuf);

	printf("\n *** Sending data to the kernel: ***");
	MYIOC_X=(int)MY_IOW(MYIOC_TYPE, 1, lbuf);
	rc = ioctl(fd, MYIOC_X, buffer);
	printf("\n rc from ioctl is %d\n\n", rc);
	
	printf("buffer in user-space is =\n		");
	for (i = 0; i < lbuf; i++)
		printf("%c", buffer[i]);
	printf("\n");

	close(fd);
	exit(0);
}
