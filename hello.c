/**
 * @file    hello.c
 * @author  Somesh koli
 * @date    
 * @version 0.1
 * @brief  An introductory "Hello World!" loadable kernel module (LKM) that can display a message
 * in the /var/log/kern.log file when the module is loaded and removed. The module can accept an
 * argument when it is loaded -- the name, which appears in the kernel log files.
*/

#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SOMESH KOLI");
MODULE_DESCRIPTION("SAMPLE LINUX KERNEL");
MODULE_VERSION("0.1");

static char *name="hello";
module_param(name,charp,S_IRUGO);
MODULE_PARM_DESC(name,"The name to display in /var/log/kern.log");

static int __init hello_init(void){
    printk(KERN_INFO "hello niggas", name);
    return 0;
}

static void __exit hello_exit(void){
    printk(KERN_INFO "goodbye nigs",name);
}

module_init(hello_init);
module_exit(hello_exit);