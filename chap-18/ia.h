/*
 * =====================================================================================
 *
 *       Filename:  ia.h
 *
 *    Description:  Header example definition
 *
 *        Version:  1.0
 *        Created:  05/13/2020 12:56:14 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */


/************************************************************************************************
 *  Definition for the infinite array (ia) package.
 * 
 * An infinite array is a array whose size can grow as needed. Adding more element 
 * to the array will just cause it grow.
 * 
 * ----------------------------------------------------------------------------------------------
 * 
 * struct infinite_array 
 *      Used to hold the information for an infinite array.
 * 
 * ----------------------------------------------------------------------------------------------
 *  Routines
 * 
 *      ia_init  -- Initializes the array. 
 *      ia_store -- Store an element in the array.
 *      ia_get   -- Gets an element from the array.
 *    
 * ***********************************************************************************************/

/* number of elemnt to store in each cell of the infinite array */
#define BLOCK_SIZE      10

struct infinite_array {
    /* the data  for this block */
    float data[BLOCK_SIZE];

    /* pointer to the next array */
    struct infinite_array *next;
};

/***********************************************************************************************
 *  ia_init -- Initializes the infinite array
 *  Parameters 
 *        array_ptr -- The array to initialize.
 ***********************************************************************************************/

#define ia_init(array_ptr)          {(array_ptr)->next = NULL;}


/***********************************************************************************************
 *  ia_get -- Get an element from an infinite array.
 *  
 * Parameters: 
 *        array_ptr -- pointer to the array to use.
 *        index     -- Index to the array.
 * 
 * Returns:
 *         The value of the element
 ***********************************************************************************************/

extern int ia_get(struct infinite_array *array_ptr, int index);


/***********************************************************************************************
 *  ia_store -- Store an element to an infinite array.
 *  
 * Parameters: 
 *        array_ptr -- pointer to the array to use.
 *        index     -- Index into the array.
 *        store_data -- data to store.
 * 
 ***********************************************************************************************/

extern void ia_store(struct infinite_array * array_pt, int index, int store_data);