/*
 * =====================================================================================
 *
 *       Filename:  find.c
 *
 *    Description:  Search through the item in the list. Return 2 if the name is found
 *                  and 0 if not found  
 *
 *        Version:  1.0
 *        Created:  05/10/2020 01:11:59 AM
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

struct linked_list {
    struct linked_list *next_ptr;
    char *data;
};

struct linked_list *first_ptr;

int find(char *name)
{
    /* current structure we are looking at */
    struct linked_list *current_ptr;
    current_ptr = first_ptr;

    while ((strcmp(current_ptr->data, name) != 0) && (current_ptr != NULL))
        current_ptr = (*current_ptr)->next_ptr;

    /* if the name is not found we go to the end of the list NULL*/
    return (current_ptr != NULL);
}

