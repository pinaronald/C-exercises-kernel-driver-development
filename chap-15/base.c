/*
 * ===================================================================================== 
 *       Filename:  base.c
 *
 *    Description:  Simple db program to lookup names in a hardcoded list. 
 *			Usage:  
 *					database
 *						Program e´will ask you a name, enter the name and 
 *						the prog will tell you if the name is in the list. 
 *							
 *						A blank name terminates the program
 *
 *        Version:  1.0
 *        Created:  05/03/2020 03:21:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#define STRING_LENGTH 80				/* Length of a typical string */
#include <stdio.h>
#include <string.h>

int main()
{
	char name[STRING_LENGTH];			/* a name to lookup */
	
	int lookup(char const *const name); /* name is contant char and constant pointer*/

	while (1) {
		printf("Enter name: ");
		fgets(name, sizeof(name), stdin);
		
		/*name is a pointer that hold the string returned from fgets*/
		/* CHeck for blank names, remember one char for new line '\n'*/
		if (strlen(name) <= 1)
			break;

		/* Get rid of new line */
		name[strlen(name)-1] = '\0';
		
		if (lookup(name))
			printf("%s is in the list\n", name);
		else
            printf("%s is not in the list\n", name);  
	}

	return (0);
}


/***************************************************************************+
 * lookup -- Looks up a name in the list
 *
 * Parameters: 
 *		name -- Name to lookup
 *
 * Returns: 
 *		1 -- Name in the lsit
 *		0 -- Name not in the list 
 *
 ***************************************************************************/


int lookup(char const *const name)
{
	/* List of people in the database, the last in a NULL for the end of 
	* the list */
	
	static char *list[] = {
		"John",
		"Jim",
		"Rick",
		"Brianne",
		"Summer",
		"Beth",
		NULL
	};

	int index;				/*index into list*/

	for (index = 0; list[index] != NULL; ++index){
		if (strcmp(list[index], name) == 0)
			return (1);
	}
	return (0);
}


