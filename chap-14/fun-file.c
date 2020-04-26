/*
 * =====================================================================================
 *
 *       Filename:  fun-file.c
 *
 *    Description:  Eneter a filename and , and find it , using fgets(), 
 *    fopen()...
 *
 *        Version:  1.0
 *        Created:  04/26/2020 11:28:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE	*in_file;
	char	name[100];  /* The filename to be opened */

	printf("Name ? ");
	fgets(name, sizeof(name), stdin);

	/* fgets() get the entire line chars including \n, we'd need to remove 
	* the last char of the name[] */
	name[strlen(name)-1] = '\0';

	in_file=fopen(name, "r");
	
	/* test the name value*/
	printf("Filename is %s\n", name);	

	if (in_file == NULL){
		fprintf(stderr, "Could not open file.\n");
		exit (8);
	}
	
	printf("File found\n");
	fclose(in_file);
	return (0);
}
