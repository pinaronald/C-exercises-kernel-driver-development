/*
 * =====================================================================================
 *
 *       Filename:  exerc-17-4.func.c
 *
 *    Description:  Function to delete an elemnt of a tree.
 *
 *        Version:  1.0
 *        Created:  05/11/2020 01:45:05 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

void delete_node(char *item)
{
    struct node *parent_ptr;
    struct node *current_ptr;
    int result;

    current_ptr = root_ptr;
    parent_prt = NULL;
    /* Walk the tree */
    while (current_ptr != NULL) {
        result = strcmp(current_ptr->data, item);

        /*node found */
        if (result == 0)
            break;
        parent_ptr = current_ptr;

        if (result > 0 )
            current_ptr = cuurent_ptr->left;

        else
            current_ptr = current_ptr->right;       
    }

    /* word not in tree */
    if (current_ptr == NULL){
        printf("Word not found \n");
        return;
    }
    
    /* If word belong to right branch of parent branch */
    if (strcmp(parent_ptr->right,item) == 0 ){ 
        /* Add left branch of the deleted node to parent*/
        parent_ptr->right = current_ptr->left;       

        /* find the bottom og the tree and add the delted right branch to bottom */
        while(parent_ptr->right != NULL)
            parent_ptr = parent_ptr->right;
        
        parent_ptr->right = current_ptr->right;
    }

    /*if word belong to the left bach of the parent branch */
    if (strcmp(parent_ptr->right,item) == 0 ){ 
        parent_ptr->left = current_ptr->left;
        while(parent_ptr->left != NULL)
            parent_ptr = parent_ptr->left;

        parent_ptr->left = current_ptr->left;
    }

}
