/*
 *
 *       Filename:  lab2_mutex1.c
 *
 *    Description:  Mutex Contention
 *   
 *      Write 3 simple modules where the second and the third one use a
 *      variale exported from the first one. The second and the third
 *      one can be identical; just give them different names. 
 *
 *      You can use the macro __stringify(KBUILD_MODNAME) to print out
 *      the module names. You can implement this by mading small
 *      modifications to your resls from the modules exercises. 
 *
 *      The exported variable should be a mutex. Have the first
 *      module initialize it in the unlocked state. 
 *
 *      The second/third module should attempt to lock the mutex,
 *      and if it is locked fail to load; Make sure you return the
 *      correct value from the initialization function. 
 *
 *      Make sure you cleanup the mutex on the cleanup function. 
 *
 *      Test by trying to load both modules simultaleously, and see if
 *      it is possible. Make sure you can load one of the modules after
 *      the other has been unloaded, to make sure you release the
 *      mutex properly.  
 *
 *        Created:  01/01/2021 09:29:12 PM
 *
 *         Author:  Ronald Pina, rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 */

#include <linux/module.h>
#include <linux/init.h>

DEFINE_MUTEX(my_mutex);
EXPORT_SYMBOL(my_mutex);

static int __init my_init(void)
{
	pr_info("\nInit mutex in unlocked state, count=%d:\n", atomic_read(&my_mutex.count));
	return 0;
}

static void __exit my_exit(void)
{
	pr_info("\nExiting with mutex having count=%d\n", atomic_read(&my_mutex.count));
} 

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LDD: chap12: lab2: mutex locks");
MODULE_LICENSE("GPL v2");

