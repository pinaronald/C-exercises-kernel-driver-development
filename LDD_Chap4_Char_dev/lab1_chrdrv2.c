/* **************** LDD:2.0 s_02/lab1_chrdrv.c **************** **
* 
Sample Character Driver 
* Improving by keeping track the umber of times the device has been
* opened and print the counter everytime the device is opened. 
*
*
*
@*/

#include <linux/module.h>	/* for modules */
#include <linux/fs.h>		/* file_operations */
#include <linux/uaccess.h>	/* copy_(to,from)_user */
#include <linux/init.h>		/* module_init, module_exit */
#include <linux/slab.h>		/* kmalloc */
#include <linux/cdev.h>		/* cdev utilities */
#define MYDEV_NAME "mycdrv"

static char *ramdisk;
#define ramdisk_size (size_t) (16*PAGE_SIZE)
static dev_t first;
static unsigned int count = 1;
static int my_major = 700, my_minor = 0;
static struct cdev *my_cdev;

static int mycdrv_open(struct inode *inode, struct file *file)
{
	static int counter = 0;
	pr_info(" OPENING device: %s:\n\n", MYDEV_NAME);
	pr_info(" MAJOR number = %d, MINOR number = %d\n", imajor(inode),
iminor(inode));
	counter++;
	pr_info("Sucessuflly opened device: %s\n\n", MYDEV_NAME);
	pr_info("It have been opened %d times since being loaded", counter);
	pr_info("ref=%d\n", (int)module_refcount(THIS_MODULE));
	return 0;

}

static int mycdrv_release(struct inode *inode, struct file *file)
{
	pr_info(" CLOSING device: %s:\n\n", MYDEV_NAME);
	return 0;
}

static ssize_t
mycdrv_read(struct file *file, char __user * buf, size_t lbuf, loff_t * ppos)
{
	int nbytes;
	if ((lbuf + *ppos) > ramdisk_size) {
		pr_info("trying to read past end of device,"
			"aborting because this is just a stub!\n");
		return 0;
	}
	nbytes = lbuf - copy_to_user(buf, ramdisk + *ppos, lbuf);
	*ppos += nbytes;
	pr_info("\n READING function, nbytes=%d, pos=%d\n", nbytes, (int)*ppos);
	return nbytes;
}

static ssize_t
mycdrv_write(struct file *file, const char __user * buf, size_t lbuf,
	     loff_t * ppos)
{
	int nbytes;
	if ((lbuf + *ppos) > ramdisk_size) {
		pr_info("trying to read past end of device,"
			"aborting because this is just a stub!\n");
		return 0;
	}
	nbytes = lbuf - copy_from_user(ramdisk + *ppos, buf, lbuf);
	*ppos += nbytes;
	pr_info("\n WRITING function, nbytes=%d, pos=%d\n", nbytes, (int)*ppos);
	return nbytes;
}

static const struct file_operations mycdrv_fops = {
	.owner = THIS_MODULE,
	.read = mycdrv_read,
	.write = mycdrv_write,
	.open = mycdrv_open,
	.release = mycdrv_release,
};

static int __init my_init(void)
{
	ramdisk = kmalloc(ramdisk_size, GFP_KERNEL);
	first = MKDEV(my_major, my_minor);
	register_chrdev_region(first, count, MYDEV_NAME);
	my_cdev = cdev_alloc();
	cdev_init(my_cdev, &mycdrv_fops);
	cdev_add(my_cdev, first, count);
	pr_info("\nSucceeded in registering character device %s\n", MYDEV_NAME);
	return 0;
}

static void __exit my_exit(void)
{
	cdev_del(my_cdev);
	unregister_chrdev_region(first, count);
	pr_info("\ndevice unregistered\n");
	kfree(ramdisk);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Jerry Cooperstein");
MODULE_LICENSE("GPL v2");
