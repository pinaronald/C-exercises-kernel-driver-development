/*
 * =====================================================================================
 *
 *       Filename:  float.c
 *
 *    Description: Determine the accurancy
 *        Version:  1.0
 *        Created:  05/09/2020 07:02:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */


#include <stdio.h>

int main()
{
    /* Two numbers to work with */
    double number1, number2;
    double result;
    int counter;        /* Loop counter and accurancy check */

    number1 = 1.0;
    number2 = 1.0;
    counter = 0 ;

    while (number1 + number2 != number1){
        ++counter;
        number2 = number2 / 10;
    }
    printf("%2d digits accurancy in calculations\n", counter);

    number2 = 1.0;
    counter = 0;

    while (1) {
        result = number1 + number2;
        if(result == number1)
            break;
        ++counter;
        number2 = number2 / 10;
    }
    printf("%2d digit accuracy in storage\n", counter);

    return (0);
}
