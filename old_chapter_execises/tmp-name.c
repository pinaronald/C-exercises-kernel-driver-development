/*
 * =====================================================================================
 *
 *       Filename:  tmp-name.c
 *
 *    Description:  tmp_name -- Return a temporary filename. Each time 
 *    this function is call a new name is return. 
 *					returns  
 *						Pointer to the new filename
 *
 *        Version:  1.0
 *        Created:  04/26/2020 12:42:36 AM
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
char name[30];
char *tmp_name (void)
{
	static int sequence = 0;		/* sequence in the last leter*/
	
	++sequence;						/* Move to the next filename*/		
	
	strcpy(name, "tmp");			/* name = tmp */
	
	/* but in the sequence digit */
	name[3] = sequence + '0';
	name[4] = '\0';					/* End the string */
	
	return (name);

}


int main()
{
	char *tmp_name (void);                                                           

	printf("NAME: %s\n", tmp_name());
	return (0);

}
