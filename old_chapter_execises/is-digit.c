/*
 * =====================================================================================
 *
 *       Filename:  is-digit.c
 *
 *    Description:  Macro that returns true if a arg is decimal digit
 *
 *        Version:  1.0
 *        Created:  04/18/2020 12:36:25 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>
#define IS_DIGIT(x) ((x) >= 0 && (x) <= 9)
char line[100];

int main()                                                                      
{                                                                               
    int number;                                                                 
                                                                                
    while (1) {                                                                 
                                                                                
                                                                                
        printf("Enter the number to check if it's a digit: ");         
        fgets(line, sizeof(line), stdin);                                       
                                                                                
        sscanf(line, "%d", &number);                                            
                                                                                
        if IS_DIGIT(number)                                                    
            printf("Number %d is a digit.\n", number);                  
        else                                                                    
            printf("Number %d is not a digit.\n", number);          
                                                                                
        }                                                                       
    return (0);                                                                 
} 
