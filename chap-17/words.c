/*
 * =====================================================================================
 *
 *       Filename:  words.c
 *
 *    Description:  Scann a file and print out a list of words in ASCII format. 
 *          Usage:  words <file>
 *
 *        Version:  1.0
 *        Created:  05/10/2020 05:19:18 PM
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
#include <ctype.h>

struct node {
    struct node *left;      /* tree to the left */
    struct node *right;     /* tree to the right */
    char *word;             /* word for this tree */
};

/*  the top of the tree  */
static struct node *root = NULL; 

/**************************************************************************************
 *  memory_error -- Writes errors and dies                                            *
 **************************************************************************************/

void memory_error(void)
{
    fprintf(stderr, "Error: Out of memory\n");
    exit (8);
}

/**************************************************************************************
 *  save_string -- Saves the string on the heap
 * 
 * Parameters:
 *       string -- String to save
 * 
 * Returns:                                           
 *      pointer to the malloced section of memory with the string copied on it. 
 **************************************************************************************/

char *save_string(char *string)
{
    char *new_string;   /* where we are going to out the new string */

    new_string = malloc((unsigned) (strlen(string) + 1));

    if (new_string == NULL)
        memory_error();
    
    strcpy(new_string,string);
    return (new_string);

}

/**************************************************************************************
 *  enter -- Enter words into the tree
 * 
 *  Parameters:
 *       node -- Current node we are looking at
 *       word -- word to enter
 **************************************************************************************/

void enter(struct node **node, char *word)
{
    int result;        /* result of strcmp */

    char *save_string(char *);  /* save the string on the heap */

    /*
     * if the current node is NULL we have reached the end of the list
     * and we should create a new node 
     */
    if ( (*node) == NULL) {

        /* allocate mem for a new node */
        (*node) = malloc(sizeof(struct node));
        if ((*node) == NULL) 
            memory_error();  

        /* Initialize the new node */
        (*node)->left = NULL;
        (*node)->right = NULL;
        (*node)->word = save_string(word);
        return;
    }

    /* check to see where the word goes */
    result = strcmp((*node)->word, word);

    /* the current node already already contains the word, no entry necessary */
    if (result == 0)
        return;

    /* The word must me added in the left or right subtree */

    if (result < 0 )
        enter(&(*node)->right, word);
    else
        enter(&(*node)->left, word);    
}

/**************************************************************************************
 *  scan -- Scan the file dor words
 * 
 *  Parameters:
 *       name -- name of the file to scan
 **************************************************************************************/

void scan(char *name)
{
    char word[100]; /* word that we are working in */
    int index;      /* index into the word */
    int ch;         /* current character */
    FILE *in_file;  /* inout file */

    in_file = fopen(name, "r");
    if (in_file == NULL ) {
        fprintf(stderr, "Error: unambel to open %s\n", name);
        exit (8);
    }

    while (1) {
        /* Scan past the white space */
        while (1) {
            ch = fgetc(in_file);

            /* isalpha macro returns a non zero if the argument is a letter, or zero otherwise*/
            if (isalpha(ch) || (ch == EOF))
            break;            
        }

        if (ch == EOF)
            break;

        word[0] = ch;
        for (index = 1; index < sizeof(word); ++index) {
            ch = fgetc(in_file);
            if (!isalpha(ch))
                break;
            word[index] = ch;
        }
        /* put null at the end */
        word[index] = '\0';

        enter(&root,word);
    }
    fclose(in_file);
}

/**************************************************************************************
 *  print_tree -- Print out the words in the tree
 * 
 *  Parameters:
 *       top -- the root of the tree to print
 **************************************************************************************/

void print_tree(struct node *top)
{
    if (top == NULL)
        return;
    
    print_tree(top->left);
    printf("%s\n", top->word);
    print_tree(top->right);
}

int main(int argc, char *argv[])
{
    if (argc != 2 ){
        fprintf(stderr, "Error: wrong number of parameters\n");
        fprintf(stderr, "Usage: words <file>\n");
        exit (8);
    }

    scan(argv[1]);
    print_tree(root);
    return (0);
}


