#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include "helper.h"


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aaron Suydam");
MODULE_DESCRIPTION("A more complicated Linux char driver for testing C++ strings integration");
MODULE_VERSION("0.1");

// Function prototypes
ssize_t read(struct file *file, char __user *buf, size_t count, loff_t *pos);
ssize_t write(struct file *file, const char __user *buf, size_t count, loff_t *pos);
int open(struct inode *inode, struct file *file);
int release(struct inode *inode, struct file *file);

static struct file_operations string_kmod_fops = {
    .owner = THIS_MODULE,
    .read = read,
    .write = write,
    .open = open,
    .release = release
};

struct simple_driver {
    struct cdev char_dev;
    char* ramdisk;
};


struct simple_driver* stringkm_drv;
int stringkm_majorno = 500;
dev_t stringkm_device_number;
static struct class* stringkm_class;

// Initialization and Exit
static int __init string_init(void) {
    printk(KERN_INFO "StringDriver: Initializing and making a C++ call\n");

    // Call the C++ function
    initialize_cpp_string("some+string");
    const char* returned = get_cpp_string();
    printk(KERN_ERR "StringDriver: C++ call returned: %s", returned);

    stringkm_device_number = MKDEV(stringkm_majorno, 0);
    stringkm_drv = kmalloc(sizeof(struct simple_driver), GFP_KERNEL);
    
    int retval = 0;
    retval = alloc_chrdev_region(&stringkm_device_number, 0, 1, "StringKM_Device");
    retval = stringkm_class = class_create("string_kmod_device_class");
    cdev_init(&(stringkm_drv->char_dev), &string_kmod_fops);
    retval = cdev_add(&(stringkm_drv->char_dev), stringkm_device_number, 1);
    retval = device_create(stringkm_class, NULL, stringkm_device_number, NULL, "/dev/stringkm");

    return retval; // Indicate successful initialization
}

static void __exit string_exit(void) {
    unregister_chrdev(500, "StringCD");
    deinitialize_cpp_string();
    printk(KERN_INFO "StringDriver: Exiting\n");
}

/* File Operations */


ssize_t read(struct file *file, char __user *buf, size_t count, loff_t *pos)
{
    copy_to_user(buf, get_cpp_string(), get_cpp_string_size());
    return 0;
}


ssize_t write(struct file *file, const char __user *buf, size_t count, loff_t *pos)
{
    set_cpp_string(buf);
    return 0;
}


int open(struct inode *inode, struct file *file)
{
    return 0;
}


int release(struct inode *inode, struct file *file)
{
    return 0;
}




module_init(string_init);
module_exit(string_exit);
