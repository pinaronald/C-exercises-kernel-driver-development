/*
 * =====================================================================================
 *
 *       Filename:  exc-14-5.c
 *
 *    Description:  copies a file_ptr and removes all character with the high 
 *    bit set,  (ch & 0x80) != 0 
 *
 *        Version:  1.0
 *        Created:  05/01/2020 10:31:16 PM
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

int main(int argc, char *argv[])                                                
{                                                                               
    char ch;                                                                    
    FILE *infile_ptr, *outfile_ptr;                                                     
                                                                               
    if (argc != 3 ){                                                            
        fprintf(stderr, "Error, wrong number of arguments\n");                  
        fprintf(stderr, "Usage is: copy3 <infile>  <outfile>\n");       
        exit (8);                                                               
    }                                                                           
                                                                                
    infile_ptr = fopen(argv[1], "r");                                               
    if (infile_ptr == NULL) {                                                       
        fprintf(stderr, "Error, unable to open the input file\n");              
        exit (8);                                                               
    }                                                                           
                                                                                
    outfile_ptr = fopen(argv[2], "w");                                              
    if (outfile_ptr == NULL) {                                                      
        fprintf(stderr, "Error, unable to open the output file\n");             
        exit (8);                                                               
    }                                                                           
                                                                                
    while ((ch = fgetc(infile_ptr)) != EOF ) {                                      
		/* check if high bit is not set, else it will not be included */
        if ( (ch & 0x80) == 0 )  
		fputc(ch, outfile_ptr);                                                
    }                                                                 
                                                                                
    fclose(infile_ptr);                                                             
    fclose(outfile_ptr);                                                            
    return (0);                                                                 
}   



/* Testing that char high bot set is to shift/multiplay by 0x80
 * 0x80 == 1000 0000 , if the shift is not zero then it is set
 *
 * */


