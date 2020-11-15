/*
 * =====================================================================================
 *
 *       Filename:  lab2_chardrv_simple.c
 *
 *    Description:  Private data for each open. A simple char dev, each 
 *    opening of the device allocates its own data, chich is freed upon 
 *    release, thus data
 *    will not be persistent across multiple opens. 
 *
 *        Version:  1.0
 *        Created:  11/12/2020 11:11:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <linux/module.h>
#include <linux/fs.h> 		/* for filesystem operations */
#include <linux/uaccess.h> 	/* copy_(to,from)_user */
#include <linux/init.h>		/* module_init, module_exit */
#include <linux/slab.h>		/* for kmalloc  */
#include <linux/cdev.h>     /* cdev utilities */

#define  MYDEV_NAME "chardrv"

static dev_t first;
static unsigned int count = 1;
static int major = 511, minor = 0;
static struct cdev *drv_cdev;
static size_t ramdisk_size = (16*PAGE_SIZE);

static int char_drv_open(struct inode *inode, struct file *file)
{
	static int counter = 0;
	char *ramdisk = kmalloc(ramdisk_size, GFP_KERNEL);
	file->private_data = ramdisk;
	pr_info("OPENING device: %s\n\n", MYDEV_NAME);
	pr_info("DEVICE %s   Major:Minor %d:%d  \n", MYDEV_NAME, major, minor);
	counter ++;
	pr_info("DEVICE %s has been opened %d times since loaded.\n", MYDEV_NAME, counter);
	return 0;
}

static int char_drv_release(struct inode *inode, struct file *file)
{
	char *ramdisk = file->private_data;
	pr_info("CLOSING DEVICE %s\n", MYDEV_NAME);
	kfree(ramdisk);
    	return 0;
}


static ssize_t 
char_drv_read(struct file *file, char __user * buf, size_t lbuf, loff_t * ppos)
{
	char *ramdisk=file->private_data;
	int nbytes = lbuf - copy_to_user(buf, ramdisk + *ppos, lbuf);
	*ppos += nbytes;
	pr_info("\n READING function, nbytes=%d, pos=%d\n", nbytes, (int)*ppos);
    	return nbytes;
}

static ssize_t
char_drv_write( struct file *file, const char __user * buf, size_t lbuf,
			loff_t * ppos)
{
	char *ramdisk=file->private_data;
	int nbytes = lbuf - copy_from_user(ramdisk + *ppos, buf, lbuf);
	*ppos += nbytes;
	pr_info("\n WRITING function, nbytes=%d, pos=%d\n", nbytes, (int)*ppos);
	return nbytes;
}


static const struct file_operations char_drv_fops = {
	.owner = THIS_MODULE,
	.read = char_drv_read,
	.write = char_drv_write,
	.open = char_drv_open,
	.release = char_drv_release,
};

static int __init char_drv_init(void)
{
	first = MKDEV(major, minor);
	if (register_chrdev_region(first, count, MYDEV_NAME) < 0) {
		pr_err("failed to register character device region\n");
		return -1;
	}
	if (!(drv_cdev = cdev_alloc())) { 
		pr_err("cdev_alloc() failed\n");
		unregister_chrdev_region(first, count);
		return -1;
	}
	cdev_init(drv_cdev, &char_drv_fops);
	if (cdev_add(drv_cdev, first, count) < 0) {
		pr_err("cdev_add() failed");
		cdev_del(drv_cdev);
		unregister_chrdev_region(first, count);
		return -1;
	}	
	pr_info("Sucessfully registering the char device %s\n", MYDEV_NAME);
	return 0;	
}

static void __exit char_drv_exit(void)
{
	cdev_del(drv_cdev);
	unregister_chrdev_region(first, count);
	pr_info("\nDEVICE unregistered\n");
}

module_init(char_drv_init);
module_exit(char_drv_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LDD lab2_chardrv_simple.c");
MODULE_LICENSE("GPL v2");
