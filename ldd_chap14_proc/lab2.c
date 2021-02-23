/* Improve the previous example by writing a read/write proc file */

#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/slab.h>

static char *str = NULL;

static int custom_proc_show(struct seq_file *m, void *v) {
	seq_printf(m, "%s\n", str);
	return 0;
}

static ssize_t custom_proc_write(struct file* file, const char __user *buffer, 
					size_t count, loff_t *f_pos) {

	char *tmp = kzalloc((count + 1), GFP_KERNEL);
	if (!tmp)
		return -ENOMEM;
	if (copy_from_user(tmp, buffer, count)){
		kfree(tmp);
		return EFAULT;
	} 
	kfree(str);
	str = tmp;
	return count;
}

static int custom_proc_open(struct inode *inode, struct file *file) {
	
	return single_open(file, custom_proc_show, NULL);	
}

static struct file_operations custom_fops = {
	.owner = THIS_MODULE,
	.open = custom_proc_open,
	.release = single_release,
	.read = seq_read, 
	.llseek = seq_lseek, 
	.write = custom_proc_write,
};

static int __init custom_proc_init(void) {
	struct proc_dir_entry *entry;
	entry = proc_create("ronaldproc", 0777, NULL, &custom_fops);
	if (!entry) {
		return -1;
	} else {
		printk(KERN_INFO "Create Ronald's proc file successfully\n");
	}
	return 0;
}

static void __exit custom_proc_exit(void) {
	remove_proc_entry("ronaldproc", NULL);
	printk(KERN_INFO "Removed Ronald's proc entry\n");
}

module_init(custom_proc_init);
module_exit(custom_proc_exit);
MODULE_LICENSE("GPL");
