/*
 * =====================================================================================
 *
 *       Filename:  calc2.c
 *
 *    Description:  Calc with 4 operations
 *
 *        Version:  1.0
 *        Created:  04/12/2020 02:56:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>

char line[100];
char operator;
int result;
int value;

int main()
{
	result = 0; /* Initialize the rezult */

	/* Loop forever till we hit the break point*/
	while (1) {
		printf("Result: %d\n", result);
		printf("Enter operator and number: ");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%c %d", &operator, &value);

		if (operator == 'q' || operator == 'Q')
			break;
		
		switch (operator) {

		case '+':
			result += value;
			break;
		case '-':
			result -= value;
			break;
		case '*':
            result *= value;    
			break;                                                
        case '/': 
			if (value == 0) {
				printf("Error: Devide by zero.\n");
                printf("    Operation ignored.\n");                             
			}
			else
				result /= value;
				break;
        default: 
			printf ("Unknown operator %c\n", operator);               
	    }
	}
	return (0);
}
