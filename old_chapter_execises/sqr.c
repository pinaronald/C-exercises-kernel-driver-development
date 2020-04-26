/*
 * =====================================================================================
 *
 *       Filename:  sqr.c
 *
 *    Description:  Square calc using macros
 *
 *        Version:  1.0
 *        Created:  04/15/2020 07:50:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */
#include <stdio.h>
#define SQR(x) ((x) * (x))

int main()
{
	int i;
	for (i = 0; i < 5; ++i) 
		printf("x %d, x squared %d\n", i+1 , SQR(i+1) ) ;
		return (0);
}

