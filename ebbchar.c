#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/unaccess.h>

#define DEVICE_NAME ebbchar
#define DEVICE_CLASS ebb

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SOMESH KOLI");
MODULE_DESCRIPTION("A SIMPLE LINUX CHARACTER DRIVER");
MODULE_VERSION("0.2");

static int majorName;
static char message[256] = {0};
static short size_of_message;
static int times_opened = 0;
static struct class *ebbcharClass = NULL;
static struct device *ebbcharDevice = NULL;

static int dev_open(struct inode *, struct file *);
static int dev_release(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_T, loff_t *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t);

static struct file_options fops =
    {
        .open = dev_open;
.release = dev_release;
.read = dev_read;
.writ = dev_write;
}
;

static int __init ebbchar_init(void){
    printk(KERN_INFO "EBBCHAR started\n");

    majorName=register_chrdev(0,DEVICE_NAME,&fops);
    if(majorName<0){
        printk(KERN_INFO "failed to register major number\n");
        return majorName;
    }

    printk(KERN_INFO "device registered successfully with major number as %d\n",majorName);
    ebbcharClass=class_create(THIS_MODULE,CLASS_NAME);
    if(IS_ERR(ebbcharClass)){
        unregister_chrdev(majorName,DEVICE_NAME);
        printk(KERN_INFO "failed to register device class\n")
    }
}