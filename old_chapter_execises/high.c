/*
 * =====================================================================================
 *
 *       Filename:  high.c
 *
 *    Description:  Check why DIRECT_CONNECT flag doesn't work
 *
 *        Version:  1.0
 *        Created:  04/18/2020 04:34:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>

const int HIGH_SPEED = (1<<7); /*Modem is running fast - 10000000 - 0x80*/
const int DIRECT_CONNECT = (1<<8); /* We are using a wired connection*/

char flags = 0; /* Start with zero */

int main()
{
	flags |= HIGH_SPEED;
	flags |= DIRECT_CONNECT;

	if((flags & HIGH_SPEED) != 0 )
		printf(" High speed is set\n");
	
	if((flags & DIRECT_CONNECT) != 0 )
        printf(" Direct connect is set\n");                                           

	return (0);

}
