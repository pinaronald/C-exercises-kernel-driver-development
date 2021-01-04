/*
 *
 *       Filename:  lab3_ioctl_signal_test.c
 *
 *    Description:  Using ioctl's to send signals. (User level sending
 *    application).
 *
 *        Created:  01/04/2021 12:34:50 AM
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
#include <string.h>
#include <signal.h>

#define MYIOC_TYPE 'k'
#define MYIOC_SETPID  (int)_IO(MYIOC_TYPE, 1)
#define MYIOC_SETSIG  (int)_IO(MYIOC_TYPE, 2)
#define MYIOC_SENDSIG (int)_IO(MYIOC_TYPE, 3)
#define SIGDEFAULT SIGSEGV

int main(int argc, char *argv[])
{
	int fd, rc;
	unsigned long pid, sig;
	char *nodename = "/dev/mycdrv";

	/*set up the message */
	pid = getpid();
	sig = SIGDEFAULT;

	if (argc > 1)
		pid = atoi(argv[1]);	
    if (argc > 2)
        sig = atoi(argv[2]);
    if (argc > 3)
        nodename = argv[3];

	/* open the device node */
	fd = open(nodename, O_RDWR);
	printf(" I opened the device, file descriptor = %d\n", fd);
	
	/* send the IOCTL to set the PID */
	rc = ioctl(fd, MYIOC_SETPID, pid);
	printf(" \n\n rc from ioctl seting pid = %d \n", rc);

	/* send the ioctl to set the signal */
	rc = ioctl(fd, MYIOC_SETSIG, sig);
    printf(" \n\n rc from ioctl seting signal = %d \n", rc);
	
	/* send the ioclt to send the signal */
	rc = ioctl(fd, MYIOC_SENDSIG, "anything");
	printf("\n\n rc from sending signal is = %d \n\n", rc);

	close(fd);
	printf("\n\n Finishedm terminating normallly\n");

	exit(0);
}
