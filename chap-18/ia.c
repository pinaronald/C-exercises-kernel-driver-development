/*
 * =====================================================================================
 *
 *       Filename:  ia.c
 *
 *    Description: infinite-array -- routines to handle infinite arrays 
 *       An infinite array is a routine that grows as needed. There is 
 *       no index too large for an infinite array.
 *
 *        Version:  1.0
 *        Created:  05/13/2020 01:25:18 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */


#include "ia.h"                 /* get common definitions */
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

/***********************************************************************************************
 *  ia_locate -- Get the location of an infinite array element.
 *  
 * Parameters: 
 *        array_ptr -- pointer to the array to use.
 *        index     -- Index to the array.
 *        current_index -- Pointer to the index into this bucket (returned).
 * 
 * Returns:
 *         pointer to the current bucket
 ***********************************************************************************************/

static struct infinite_array *ia_locate(struct infinite_array *array_ptr, int index, int *current_index_ptr)
{
    /* pointer to the current bucket */
    struct infinite_array *current_ptr;

    current_ptr = array_ptr;
    *current_index_ptr = index;

    while (*current_index_ptr >= BLOCK_SIZE) {
        if(current_ptr->next == NULL){

            current_ptr->next = malloc(sizeof(struct infinite_array));

            if(current_ptr->next == NULL) {
                fprintf(stderr, "Error: Out of memory");
                exit (8);
            }

            memset(current_ptr->next, '\0', sizeof(struct infinite_array)); /* fill the memeory with a specific byte */

        }
        current_ptr = current_ptr->next;
        *current_index_ptr -= BLOCK_SIZE; 
    }
    return(current_ptr);
}

/***********************************************************************************************
 *  ia_store -- Stores an element into an infinite array
 *  
 *  Parameters: 
 *        array_ptr -- pointer to the array to use.
 *        index     -- Index to the array.
 *        store_data -- data to store
 * 
 ***********************************************************************************************/

void ia_store(struct infinite_array * array_ptr, int index, int store_data)
{
    /* pointer to the current bucket */
    struct infinite_array  *current_ptr;
    int current_index;      /* index into the current bucket */

    current_ptr = ia_locate(array_ptr, index, &current_index);
    current_ptr->data[current_index] = store_data;
}

/***********************************************************************************************
 *  ia_get -- Gets an element from an infinite array.
 *  
 *  Parameters: 
 *        array_ptr -- pointer to the array to use.
 *        index     -- Index to the array.
 *     
 *  Returns 
 *        the value of the element.
 * 
 * Note: you can also get the value of an elemnt that was not previously stored, its value
 * is zero.
 ***********************************************************************************************/

int ia_get(struct infinite_array *array_ptr, int index)
{
    /* pointer to the current bucket */
    struct infinite_array *current_ptr;
    int current_index;  /* index into the current bucket */

    current_ptr = ia_locate(array_ptr, index, &current_index);
    return (current_ptr->data[current_index]);
}

