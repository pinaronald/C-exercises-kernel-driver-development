/*
 *
 *       Filename:  lab1_sem1.c
 *
 *    Description:  Semaphore Contention
 *   
 *      Write 3 simple modules where the second and the third one use a
 *      variale exported from the first one. The second and the third
 *      one can be identical; just give them different names. 
 *
 *      You can use the macro __stringify(KBUILD_MODNAME) to print out
 *      the module names. You can implement this by mading small
 *      modifications to your resls from the modules exercises. 
 *
 *      The exported variable should be a semaphore. Have the first
 *      module initialize it in the unlocked state. 
 *
 *      The second/third module should attempt to lock the semaphore,
 *      and if it is locked fail to load; Make sure you return the
 *      correct value from the initialization function. 
 *
 *      Make sure you cleanup the semaphore on the cleanup function. 
 *
 *      Test by trying to load both modules simultaleously, and see if
 *      it is possible. Make sure you can load one of the modules after
 *      the other has been unloaded, to make sure you release the
 *      semaphore properly.  
 *
 *        Created:  01/01/2021 08:24:20 PM
 *
 *         Author:  Ronald Pina, rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 */

#include <linux/module.h>
#include <linux/init.h>
#include <asm/atomic.h>
#include <linux/version.h>
#include <linux/semaphore.h>


#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,37)
DECLARE_MUTEX(my_sem);
#else
DEFINE_SEMAPHORE(my_sem);
#endif
EXPORT_SYMBOL(my_sem);

static int __init my_init(void)
{
	pr_info("\nInitializing semaphore, semaphore_count=%u\n", my_sem.count);
	return 0;
}

static void __exit my_exit(void)
{
	pr_info("\nExiting semaphore, semaphore_count=%u\n", my_sem.count);
} 

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LDD chap12 semaphore locks");
MODULE_LICENSE("GPL v2");

