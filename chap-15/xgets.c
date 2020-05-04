/*
 * =====================================================================================
 *
 *       Filename:  xgets.c
 *
 *    Description:  extended_fgets -- Get a line from inout file and record it and save to a file.
 *		Parametrs:	
 *			line -- The line to read. 
 *			size -- sizeof(line) max characters to read
 *			file -- file to read data from
 *		  Return:
 *			NULL -- error or end of the file in read
 *			otherwise line 
 *
 *        Version:  1.0
 *        Created:  05/03/2020 04:03:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>

FILE *save_file = NULL;		/* the main program opens this file if -S is on the cmd */

char *extended_fgets(char *line, int size, FILE *file)
{
	char *result; 		/* reslut of fgets */
	result = fgets(line, size, file);
	
	/* Did someone asked for a save file */
	if (save_file != NULL)
		fputs(line, save_file);       /* save line into the file */

	return (result);
	
}
