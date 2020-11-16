/*
 * =====================================================================================
 *
 *       Filename:  example_linked.c
 *
 *    Description:  Example of a linked list initalization and usage
 *    using kernel fumctions.
 *
 *        Version:  1.0
 *        Created:  11/15/2020 11:20:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

LIST_HEAD(my_list);

struct my_enrty {
	struct list_head list;
	int integervar;
	char stringvar[30];
};


static void mylist_init(void)
{
	struct my_entry *me;
	int j;
	for (j = 0; j < NUMTRY; j**) {
		me = kmalloc(sizeof(my_enrty), GFP_KERNEL);
		me->integervar = j;
		sprintf(me->stringvar, "My_%d", j + 1);

		/* list_add(struct list_head *entry, struct list_head *head) */
		list_add(&me->list, &my_list);
	}
}

static int walk_list(void)
{
	int j = 0;
	struct list_head *l;
	
	if(list_empty(&my_list))
		return 0;
/**
 * Iterate over the list
 *  #define list_for_each(pos, head) \
 *      for (pos = (head)->next; pos != (head); pos = pos->next)
 *  @pos:    the &struct list_head to use as a loop cursor.
 *  @head:   the head for your list.
 **/

/**
 * list_entry - get the struct for this entry
 *  @ptr:    the &struct list_head pointer.
 *  @type:   the type of the struct this is embedded in.
 *  @member: the name of the list_head within the struct.
 *     list_entry(ptr, type, member)
 */

	list_for_each(l, &my_list) {
		struct my_enty *me = list_entry(l, struct my_entry, list);
		foobar(&me->integervar);
		j++;
	}
	return j;
}
