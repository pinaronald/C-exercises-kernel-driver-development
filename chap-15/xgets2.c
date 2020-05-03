/*
 * =====================================================================================
 *
 *       Filename:  xgets2.c
 *
 *    Description:  Version 2 of extended xgets, when enabled the input will not taken from 
 *					keyboard but from the previously genertated file. 
 *    	Parametes:  line, size, file, returns NULL or line, jsut like fgets
 * 
 *       Version:  2.0
 *        Created:  05/03/2020 09:24:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>
FILE *save_file = NULL;
FILE *playback_file = NULL;

char *extended_fgets(char *line, int size, FILE *file)
{
	extern FILE save_file;					/* file to save strings in */
	extern FILE playback_file;				/* file for alternative input */
	char *results;


	if (playback_file != NULL) {
		result = fgets(line, sizeof(line), playback_file);
		/* echo the input to standart out */
		fputs(line, stdout);
	} else 
		result = fgets(line, sizeof(line), file);

	/* if save_file prt is not null */

	if (save_file != NULL )
		fputs(line, save_file);

	return (result);
}
