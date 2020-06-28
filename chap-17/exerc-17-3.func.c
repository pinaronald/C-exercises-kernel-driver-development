/*
 * =====================================================================================
 *
 *       Filename:  exerc-17-3.func.c
 *
 *    Description:  Function to delete an element of a double linked list
 *
 *        Version:  1.0
 *        Created:  05/11/2020 01:23:04 AM
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

struct double_list {
    char data[30];
    struct double_list *next_ptr;
    struct double_list *pre_ptr;
};

void delete_item(struct double_list *first_ptr, char *item)
{
    struct double_list *before_ptr;
    struct double_list *current_ptr;

    current_ptr = first_ptr;

    /* lookup the list */
    while ((strcmp(current_ptr->data, item) != 0) && (current_ptr != NULL)){
        before_ptr = current_ptr;
        current_ptr = current_ptr->next_ptr;
    }

    if (current_ptr == NULL){
        fprintf(stderr,"Error: item not found\n");
        exit (8);
    }
    /* Delete item */
    before_ptr->next_ptr = current_ptr->next_ptr;
 
    if (current_ptr->next_ptr != NULL)
        current_ptr->next_ptr->pre_ptr = before_ptr;

    free(current_ptr);
    current_ptr = NULL;
}
