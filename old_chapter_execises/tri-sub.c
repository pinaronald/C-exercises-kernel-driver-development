/*
 * =====================================================================================
 *
 *       Filename:  tri-sub.c
 *
 *    Description:  Trianle calc area func
 *
 *        Version:  1.0
 *        Created:  04/14/2020 02:00:24 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>

float triangle(float width, float height)
{

	float area;
	area = width * height / 2.0;
	return (area);
}


int main()
{
	printf("Triangle #1 %f\n", triangle(4.3, 8.3));
    printf("Triangle #2 %f\n", triangle(4.8, 9.8));                             
    printf("Triangle #3 %f\n", triangle(6.2, 2.0));                             
	return (0);
}
