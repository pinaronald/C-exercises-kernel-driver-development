/* Create a proc entry using proc_create*/

#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>


static int custom_proc_show(struct seq_file *m, void *v) {

	seq_printf(m, "Custom proc!\n");
	return 0;
}

static int custom_proc_open(struct inode *inode, struct file *file) {

	return single_open(file, custom_proc_show, NULL);
}

static const struct file_operations custom_proc_fops = {
	.owner = THIS_MODULE,
	.open = custom_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};

static int __init custom_proc_init(void) {

	proc_create("custom_proc", 0, NULL, &custom_proc_fops);
	return 0;
}

static void __exit custom_proc_exit(void) {
	
	remove_proc_entry("custom_proc", NULL);
}

MODULE_LICENSE("GPL");
module_init(custom_proc_init);
module_exit(custom_proc_exit);
