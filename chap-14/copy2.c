/*
 * =====================================================================================
 *
 *       Filename:  copy2.c
 *
 *    Description:  Copies a file to another, using unbufferd IO.
 *			Usage:	copy <from> <to>
 *
 *        Version:  1.0
 *        Created:  04/27/2020 01:56:58 AM
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
#ifndef __MSDOS__
#define __UNIX__
#endif

#ifdef __UNIX__
#include <sys/types.h>  /* File defines for unix filesystem */
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#endif

#ifdef __MSDOS__                                                           
#include <fcntl.h>                                                              
#include <sys\stat.h>
#include <io.h>
#endif 

#ifndef O_BINARY
#define O_BINARY 0			/* Define the flag if not defined yet */
#endif

#define BUFFER_SIZE (16 * 1024)  /* use 16K buffers */

int main( int argc, char *argv[])
{
	char buffer[BUFFER_SIZE];    /* buffer for data, or the pointer to palce for data */
	int in_file;				 /* input file descriptor */
	int out_file;				 /* optput file descriptor */
	int read_size;				 /* number of bytes on last read */

	if (argc != 3 || strcmp(argv[1], "--help") == 0) {
		fprintf(stderr, "Usage is: copy <from> <to>\n");
		exit (8);
	}

	in_file = open(argv[1], O_RDONLY|O_BINARY);
	if (in_file < 0){
        fprintf(stderr, "Error: unamble to open %s\n", argv[1]);                          
        exit (8);                                                               
    }

	out_file = open(argv[2], O_WRONLY|O_TRUNC|O_CREAT|O_BINARY, 0666);
	if (out_file < 0){                                                           
        fprintf(stderr, "Error: unamble to open %s\n", argv[2]);                
        exit (8);                                                               
    }     
	
	while (1)  {
		read_size = read(in_file, buffer, sizeof(buffer));

		if (read_size == 0 )
			break;    /* end of file*/
		
		if (read_size < 0) {
		    fprintf(stderr, "Error: unable to read data");                
			exit (8);
		}
		write(out_file, buffer, (unsigned int) read_size);				
	}
	close(in_file);
	close(out_file);
	return (0);
}
   
