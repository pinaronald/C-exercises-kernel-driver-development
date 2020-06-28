/*
 * =====================================================================================
 *
 *       Filename:  exerc-17-2.func.c
 *
 *    Description:  Function to delete an element of a lineked list.
 *
 *        Version:  1.0
 *        Created:  05/11/2020 12:44:14 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

struct linked_list {
    char data[30];
    struct linked_list *next_ptr;
}

void delete_item(struct linked_list *first_ptr, char *name)
{
    
    struct linked_list *current_ptr;
    struct linked_list *before_ptr;
 
    current_ptr = first_ptr; /* Initialize current_ptr*/
    
    /* lookup the item */
    while ((strcmp(current_ptr->data), name != 0) && (current_ptr != NULL)){
        before_ptr = current_ptr;
        current_ptr = current_ptr->next_ptr;
    }

    if (current_ptr == NULL){
        fprintf(stderr, "Element not found in the list\n");
        exit(8)
    }
    /* delete the elemt*/
    before_ptr->next_ptr = current_ptr->next_ptr;
    free(current_ptr);
    current_ptr = NULL;
}
