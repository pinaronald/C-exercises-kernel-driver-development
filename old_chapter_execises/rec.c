/*
 * =====================================================================================
 *
 *       Filename:  rec.c
 *
 *    Description:  i
 *
 *        Version:  1.0
 *        Created:  04/15/2020 09:04:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>
#define RECIPROCAL (number) (1.0 / (number))

int main()
{
	float counter;

	for (counter = 1.0; counter < 10.0; counter += 1.0 )
		printf("1/%f = %f\n", counter, RECIPROCAL(counter));
	return (0);
}

