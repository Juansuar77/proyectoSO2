#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

#define PROC_NAME "hello_kernel"

static int hello_show(struct seq_file *m, void *v)
{
    seq_printf(m, "Hello World");
    return 0;
}

static int hello_open(struct inode *inode, struct file *file)
{
    return single_open(file, hello_show, NULL);
}

static const struct proc_ops hello_proc_ops = {
    .proc_open = hello_open,
    .proc_read = seq_read,
    .proc_lseek = seq_lseek,
    .proc_release = single_release,
};

static int __init hello_init(void)
{
    proc_create(PROC_NAME, 0, NULL, &hello_proc_ops);
    printk(KERN_INFO "Hello World: modulo cargado\n");
    return 0;
}

static void __exit hello_exit(void)
{
    remove_proc_entry(PROC_NAME, NULL);
    printk(KERN_INFO "Hello World: modulo removido\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Juan_Suar");
MODULE_DESCRIPTION("Modulo Hello World con archivo en /proc");
