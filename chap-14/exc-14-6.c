/*
 * =====================================================================================
 *
 *       Filename:  exc-14-6.c
 *
 *    Description:  Design a file format store a persons name address, and 
 *					other info, Write a program to read this file and 
 *					produce a set of mailing labels. 
 *
 *        Version:  1.0
 *        Created:  05/02/2020 12:12:18 AM
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
#include <stdlib.h>

struct mailing {
	char first_name[50];
	char last_name[50];
	char address[50];
	char email[40];
};
	

int main (int argc, char *argv[])
{
                                                                   
    FILE *infile_ptr;
	char *line = NULL;
	size_t len = 0;
	struct mailing subscriber;
                                     
    if (argc != 2 ){                                                            
        fprintf(stderr, "Error, wrong number of arguments\n");                  
        fprintf(stderr, "Usage is: mail <input file>  <output file>\n");       
        exit (8);                                                               
    }                                                                           
                                                                                
    infile_ptr = fopen(argv[1], "r");                                               
    if (infile_ptr == NULL) {                                                       
        fprintf(stderr, "Error, unable to open the input file\n");              
        exit (8);                                                               
    }                                                                           
                                                                                
    while ((getline(&line, &len,infile_ptr)) != -1 ) {                                      

		/* Remove the newline cha in the nad of the line string */
	line[strlen(line) - 1] = '\0';
	/* Fetch the first line */
	if ((strncmp(line, "first name", 10)) ==  0)
		strcpy(subscriber.first_name, &line[12]); /* Getst the name starting from char 11*/

	if ((strncmp(line, "last name:", 10)) ==  0)                             
            strcpy(subscriber.last_name, &line[11]); 

        if ((strncmp(line, "address:", 8)) ==  0)                             
            strcpy(subscriber.address, &line[9]); 

        if ((strncmp(line, "email:", 6)) ==  0)                             
            strcpy(subscriber.email, &line[7]); /* Getst the name starting from char 11*/
    }

	printf("\n Printing user information\n");
	printf("=============================\n");
	printf("First name: %s\n", subscriber.first_name);
	printf("Last name: %s\n", subscriber.last_name);
	printf("Email: %s\n", subscriber.email); 
    printf("Adress: %s\n", subscriber.address);
    fclose(infile_ptr);                                                             
    return (0);                                                                 
}                                                                               




