/*
 * =====================================================================================
 *
 *       Filename:  switch-continue.c
 *
 *    Description:  Demonstarate the role of "contunue" and "break" inside 
 *    a switch and loop. The program converts the numbers. 
 *
 *        Version:  1.0
 *        Created:  04/13/2020 10:12:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>

int number; /*number that we are converting*/
char line[100]; /*inut line*/
char type; /*the typer of convert*/


int main()
{

	while (1) { /* point 2*/
		printf("Enter conversion and number: ");
	
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%c", &type);

		if (type == 'q' || type == 'Q' )
			/*break the loop and exit, go to point 4*/
			break;

		switch (type) {
			case 'o':
			case 'O': /* Octal conversion*/
				sscanf(line, "%c %o",&type, &number);
				/*break the switch, go to end, ponit 3*/
				break;
			case 'x':
			case 'X': /*Hex conversion*/
		        sscanf(line, "%c %x",&type, &number);  
                break;                                                                 
            case 'd':                                                           
            case 'D': /*Dec conversion*/                                        
                sscanf(line, "%c %d",&type, &number);                                  
                break;                                                          
            case '?':                                                           
            case 'h': /* Help */  
				printf("Letter conversion\n");
                printf("  o    Octal\n");                                  
                printf("  x    Hex\n");                                  
                printf("  d    Dec\n");                                  
                printf("  q    Quit program\n");                                  
				/*Dont't print number*/
				/*Go on top of the loop, point 2*/
				continue;
			default:
				printf("Type ? for help\n");
				continue;
		}
		printf(" Result is %d\n", number); /* Point 3*/
	}
	return (0); /*#Point 4#*/
}


