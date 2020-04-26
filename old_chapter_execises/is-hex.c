/*
 * =====================================================================================
 *
 *       Filename:  is-hex.c
 *
 *    Description:  Second macro to check if it is hex
 *
 *        Version:  1.0
 *        Created:  04/18/2020 12:50:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>
#define IS_DIGIT(x) ((x) >= 0 && (x) <= 9)
#define IS_HEX(x) ((IS_DIGIT(x)) || ((x) >= 'a' && (x) <='f') || ((x) >= 'A' && (x) <= 'F'))

int main()
{
	if IS_HEX('B')
		printf("B is hex");
	return (0);
	
}
