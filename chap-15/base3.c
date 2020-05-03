/*
 * =====================================================================================
 *
 *       Filename:  base2.c
 *
 *    Description:  the previous base2.c -- record the comand entered by the user
 * 											 and can load from a file if -P is used. 
 *
 *        Version:  3.0
 *        Created:  05/03/2020 04:18:24 PM
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

FILE *save_file = NULL; 		/*save file if any */ 
FILE *playback_file = NULL;		

char *extended_fgets(char *, int, FILE *);

int main(int argc, char *argv[])
{
	char name[80];
	char *name_file_save; 		/* name of the file to save */
	char *name_file_playback;
	int lookup(char const *const name);

	/* Check and fetch the option first */

	while ((argc > 1) && (argv[1][0] == '-')) {

		switch (argv[1][1]) {

			case 'S': 
				name_file_save = &argv[1][2];
				/* this will open the fine name and will return a valid pointer */
				save_file = fopen(name_file_save, "w");
				if (save_file == NULL) 
					fprintf(stderr, "Warning: unable to open %s\n", name_file_save);
				break;

			case 'P':
				name_file_playback = &argv[1][2];
				playback_file = fopen(name_file_playback, "r");
				if (playback_file == NULL)
					fprintf(stderr, "Warning: unable to open %s\n", name_file_playback);
				break;

			default: 
				fprintf(stderr, "Bad option: %s\n", argv[1]);
				exit (8);
		}
		++argv;
		--argc;
	}

	while (1) {
		printf("Enter name: ");

		/* using the new extended fgets, if -S is specifide, the file will be opened,
		 * in using -P the inout will be read from file. */ 
		extended_fgets(name, sizeof(name), stdin);

		if (strlen(name) <= 1)
			break;

		name[strlen(name)-1] = '\0';

		if(lookup(name))
			printf("%s is in the list\n", name);
		else
			printf("%s is in not the list\n", name);
	}
	
	if (save_file != NULL)
		fclose(save_file);

	if (playback_file != NULL)
		fclose(playback_file);

	return (0);	
}

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

	int index;              /*index into list*/

	for (index = 0; list[index] != NULL; ++index){
		if (strcmp(list[index], name) == 0)
			return (1);
	}
	return (0);
}

char *extended_fgets(char *line, int size, FILE *file)
{
	char *result; /*result of fgets*/

	/*check if save_file pointer or if playback_file ptr  is valid, 
	* wich means the file has been opened for writing */
	if (playback_file != NULL) {
		result = fgets(line, size, playback_file);	
		fputs(line, stdout); 	/* print the read dtring to stdout*/
	} else 
		result = fgets(line, size, file);
	
	/*in save-file scpecified*/

	if (save_file != NULL)
		fputs(line, save_file);

	return(result);
}


