/*
 * =====================================================================================
 *
 *       Filename:  list.p1.c
 *
 *    Description:  Add an elemt on a sorted linked list.
 *
 *        Version:  1.0
 *        Created:  05/10/2020 01:48:00 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */


void enter(struct item *first_ptr, const int value)
{
    struct item *before_ptr;        /* item before this one */
    struct item *after_ptr;         /* item after this one */
    struct item *new_item_ptr;      /* the new item to add */

    /* create the new item to add to the list */

    before_ptr = first_ptr;             /* start at the begining */
    after_ptr = before_ptr->next_ptr;   

    while (1) {
        if (after_ptr == NULL)
            break;

        if (after_ptr->value >= value)
            break;
        
        /* advance the pointer */
        after_ptr = after_ptr->next_ptr;
        before_ptr = before_ptr->next_ptr;
    }
}

....

/* create the new elemnt and link it */

new_item_ptr = malloc(sizeof(struct item));
new_item_ptr->value = value;                    /* set  value of item */

before_ptr->next_ptr = new_item_ptr; 
new_item_ptr->next_ptr = after_ptr;
}