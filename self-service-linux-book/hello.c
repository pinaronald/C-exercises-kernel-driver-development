#include <stdio.h>
#include <stdlib.h>

struct linked_list_struct {
    int list_no;
    int data;
    struct linked_list_struct *pNext;
};

int main(void)
{
    int stack_int = 3;
    char struct_string[16];
    struct linked_list_struct *node1 = (struct linked_list_struct*)
            malloc(sizeof(struct linked_list_struct));
    struct linked_list_struct *node2 = (struct linked_list_struct*)
            malloc(sizeof(struct linked_list_struct));
    struct linked_list_struct *node3 = (struct linked_list_struct*)
            malloc(sizeof(struct linked_list_struct));      

    node1->list_no = 1;
    node1->data = 9234;
    node1->pNext = node2;

    node2->list_no = 2;
    node2->data = 2342;
    node2->pNext = node3;

    node3->list_no = 3;
    node3->data = 7987;
    node3->pNext = node1;

    printf("DDD is a wonderful GUI tool\n");

    stack_int = 5;
  
    return(0);
}
