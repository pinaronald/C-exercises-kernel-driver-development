/*
 * ==========================================================================
 *
 *       Filename:  lab1_linked_module.c
 *
 *    Description:  LAB 1: Linked lists.
 *
 *    Write a module that sets up a double-linked circular list of data
 *    structure. The data structure can be as simple as integer
 *    variables. 
 *
 *    Test inserting and deleting elements in the list. 
 *
 *    Walk through the list using list_entry() and print out values to
 *    make sure the insertion and deletion process are working.
 *
 *        Version:  1.0
 *        Created:  11/15/2020 11:50:57 PM
 *
 *         Author:  Ronald Pina, rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * ========================================================================
 */

#include <linux/module.h>
#include <asm/atomic.h>
#include <linux/errno.h>
#include <linux/slab.h>
#include <linux/init.h>

/* We'll do a dog race */
static LIST_HEAD(dog_list);

struct dog_entry {
	struct list_head dlist; /* link in dog list*/
	int gate;			    /* assign gates in the race */
	char name[20];			/* dog's name */
};


static int __init my_init(void)
{
	struct dog_entry *de;
	int j;

	for (j = 1; j < 6; j++) {
		if(!(de = kmalloc(sizeof(struct dog_entry), GFP_KERNEL))){
			pr_info("Dogs: failed to allocate memory for dog %d \n", j);
			return -ENOMEM;
		}
	de->gate = 10 + j;  /* gate number */
	sprintf(de->name, "Dog_%d", j );
	pr_info(" Dogs: adding %s at gate %d to dog_list", de->name, de->gate);
	list_add(&de->dlist, &dog_list);
	}
	return 0;
}



static void __exit my_exit(void)
{
	struct list_head *list;	 /* pointer to list head object */
	struct list_head *tmp;	 /* temporary list head for safe deletion */

	if (list_empty(&dog_list)){
		pr_info("Dogs (exit): dog list is empty!\n");
		return;
	}
	pr_info("Dogs (exit): dog list is NOT empty!\n");

	/* walk the list safe against removal of list entry */
	list_for_each_safe(list, tmp, &dog_list) {
		struct dog_entry *de = list_entry(list, struct dog_entry, dlist);
		list_del(&de->dlist);
		pr_info("Dogs (exit): %s at gate %d removed from the list! \n", 
					de->name, de->gate);
		kfree(de);
	}
	
	/* Let's test if we removed the dog entry */

	if (list_empty(&dog_list))
        pr_info("Dogs (done): dog list is empty!\n");
	else
		pr_info("Dogs (done): dog list is NOT empty ");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LDD: Chap7: Linked list module");
MODULE_LICENSE("GPL v2");

