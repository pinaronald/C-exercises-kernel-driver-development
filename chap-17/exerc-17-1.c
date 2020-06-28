/*
 * =====================================================================================
 *
 *       Filename:  exerc-17-1.c
 *
 *    Description:  Cross reference program, extracting all the words of a text file and
 *    placing on a tree
 *
 *        Version:  1.0
 *        Created:  05/10/2020 10:40:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Declare the tree node srtucture */

struct node {
    char *word;
    struct node *left;
    struct node *right;
};

/* Declare the top of the tree , we name it root */

static struct node *root = NULL;

void memory_error(void)
{
    fprintf(stderr, "Error: out of memory\n");
    exit (8);
}

/* Function save_string, save the string on the heap and return the malloced string pointer*/

char *save_string(char *string)
{
    char *new_string;
    new_string = malloc(sizeof(string) + 1);

    if (new_string == NULL)
        memory_error();

    strcpy(new_string, string);

    return (new_string);
}

/**********************************************************************
 *  enter_word -- enter words into the tree
 * 
 *  Parameters:
 *          node -- current node we are looking at
 *          word -- the word to add
 **********************************************************************/

void enter_word(struct node **node, char *word)
{
    int result;

    char search_string(char *);

    /* if current node is null, end list, we should create a new node */
    if ((*node) == NULL){
        
        (*node) = malloc(sizeof(struct node));
        if ((*node) == NULL)
            memory_error();
        
        (*node)->left = NULL;
        (*node)->right = NULL;
        (*node)->word = save_string(word);
    }

    /* check to see where the word goes */
    result = strcmp((*node)->word, word);

    /* the current node already contain the word, do not add */ 
    if (result == 0)
        return;
    
    /* the word must be added to the laeft or right */
    if (result < 0)
        enter_word(&(*node)->right, word) ;
    else
        enter_word(&(*node)->left, word);
}

/**************************************************************************
 *  Scan the file for words and alls the enter_word function
 *  parameter -- name of the file
 **************************************************************************/

void scan_file(char *name)
{

    char word[100]; /* word that we are working in */
    int i;
    int ch;
    FILE *in_file;

    in_file = fopen(name, "r");
    if (in_file == NULL){
        fprintf(stderr,"Error: unable to open %s\n", name);
        exit (8);
    }

    while (1) {
        
        while (1){
            ch = fgetc(in_file);
            if (isalpha(ch) || (ch == (EOF)))
            break;
        }

        if (ch == EOF)
            break;
        
        word[0] = ch;
        for (i = 1; i < sizeof(word); ++i){
            ch = fgetc(in_file);
            if(!isalpha(ch))
                break;
            word[i] = ch;
        }

        word[i] = '\0';    /*put null in the end */
        enter_word(&root, word);
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
    if (argc !=2 ){
        fprintf(stderr, "Error: usage is : cross-ref <file>");
        exit (8);
    }
    scan_file(argv[1]);
    print_tree(root);
    return (0);
}