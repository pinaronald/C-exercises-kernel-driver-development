/*
 *
 *       Filename:  lab3_ioctl_signal.c
 *
 *    Description:  Using ioctl's to send signals.
 *
 *    	It is sometimes desirable to send a signal to an aplication from
 *      the kernel. The function for doing this is:
 *
 *      int send_sig(int signal, struct task_struct *tsk, int priv)
 *
 *      where signal is the signal to send, tsk points to the task
 *      structre corresponding to the process which the signal should be
 *      sent, and prov indicates the proviledge level. ( 0 for user app,
 *      1 for the kernel).
 *
 *      Write a character driver that has three ioctl commands:
 *
 *      	* Set the process ID to which sinals should be sent.
 *      	* Set the signal which should be set.
 *      	* Send the signal.
 *
 * 		Remeber, you'll have to use pid_task(find_vpid(pid), PIDTYPE_PID) 
 * 		to connect the  pid to the task structure it corresponds with. 
 *
 * 		You'l have to develop the sending program:
 *
 * 			* If given no arguments, it should send SIGKILL to the
 * 			  current process
 * 			* If one arg is given, it should set the process ID to send
 * 			  the command.
 * 			* If given two arguments, it should also set the signal.
 *	
 *        Created:  01/03/2021 11:15:50 PM
 *
 *         Author:  Ronald Pina, rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 */

#include <linux/module.h>
#include "lab_miscdev.h"

#define MYIOC_TYPE 'k'
#define MYIOC_SETPID _IO(MYIOC_TYPE, 1)
#define MYIOC_SETSIG _IO(MYIOC_TYPE, 2)
#define MYIOC_SENDSIG _IO(MYIOC_TYPE, 3)

static int sig_pid = 0;
static struct task_struct *sig_tsk = NULL;
static int sig_tosend = SIGKILL;

static inline long
mycdrv_unlocked_ioctl(struct file *fp, unsigned int cmd, unsigned long arg)
{
	int retval;
	switch (cmd) {
	case MYIOC_SETPID:
		sig_pid = (int)arg;
		pr_info(" Setting PID to send signals to, sigpid = %d\n", sig_pid);
		/* find the task structure which corresponds to the PID*/
		sig_tsk = pid_task(find_vpid(sig_pid), PIDTYPE_PID);
		break;
	case MYIOC_SETSIG:
		sig_tosend = (int)arg;
		pr_info(" Setting signal to send as %d \n", sig_tosend);
		break;
	case MYIOC_SENDSIG:
		if(!sig_tsk) {
			pr_info(" You haven't set the PID, using current\n");
			sig_tsk = current;
			sig_pid = (int)current->pid;
		}
		pr_info("Sending signal %d to process ID %d\n", sig_tosend, sig_pid);
		retval = send_sig(sig_tosend, sig_tsk, 0);
		pr_info("retval = %d\n", retval);
		break;
	default:
		pr_info("got invalid case, CMD=%d\n", cmd);
		return -EINVAL;
	}
	return 0;
}


static const struct file_operations mycdrv_fops = {
	.owner = THIS_MODULE,
	.unlocked_ioctl = mycdrv_unlocked_ioctl,
	.open = mycdrv_generic_open,
	.release = mycdrv_generic_release
};

module_init(my_generic_init);
module_exit(my_generic_exit);


MODULE_AUTHOR("Ronald Pina, rpina@suse.com");
MODULE_DESCRIPTION("LDD: chap13: lab3: ioctl_signal");
MODULE_LICENSE("GPL v2");

