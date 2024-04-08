#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>
#include <linux/stat.h>




#define DEVICE_NAME "simplechar"
#define CLASS_NAME "simple"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Linux char driver for testing");
MODULE_VERSION("0.1");

static int majorNumber;
static char message[256] = {0};
static short size_of_message;
static int numberOpens = 0;
static struct class* simplecharClass = NULL;
static struct device* simplecharDevice = NULL;

static int dev_open(struct inode *, struct file *);
static int dev_release(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);

static struct file_operations fops = {
    .open = dev_open,
    .read = dev_read,
    .write = dev_write,
    .release = dev_release,
};

static int __init simplechar_init(void) {
    printk(KERN_INFO "SimpleChar: Initializing the SimpleChar LKM\n");

    majorNumber = register_chrdev(0, DEVICE_NAME, &fops);

    printk(KERN_INFO "SimpleChar: registered correctly with major number %d\n", majorNumber);

    simplecharClass = class_create(THIS_MODULE, CLASS_NAME);

    printk(KERN_INFO "SimpleChar: device class registered correctly\n");

    simplecharDevice = device_create(simplecharClass, NULL, MKDEV(majorNumber, 0), NULL, DEVICE_NAME);

    printk(KERN_INFO "SimpleChar: device class created correctly\n");
    printk(KERN_INFO "Attempting C++ Calls..");

    // size_t result = helper_function();

    printk(KERN_INFO, "Result should be 5. Result is : %zu", result);
    return 0;
}

static void __exit simplechar_exit(void) {
    device_destroy(simplecharClass, MKDEV(majorNumber, 0));
    class_unregister(simplecharClass);
    class_destroy(simplecharClass);
    unregister_chrdev(majorNumber, DEVICE_NAME);
    printk(KERN_INFO "SimpleChar: Goodbye from the LKM!\n");
}

static int dev_open(struct inode *inodep, struct file *filep) {
    numberOpens++;
    printk(KERN_INFO "SimpleChar: Device has been opened %d time(s)\n", numberOpens);
    return 0;
}

static int dev_release(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "SimpleChar: Device successfully closed\n");
    return 0;
}

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset) {
    int error_count = 0;
    error_count = copy_to_user(buffer, message, size_of_message);

    if (error_count == 0) {
        printk(KERN_INFO "SimpleChar: Sent %d characters to the user\n", size_of_message);
        return (size_of_message = 0);
    } else {
        printk(KERN_ALERT "SimpleChar: Failed to send %d characters to the user\n", error_count);
        return -EFAULT;
    }
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset) {
    sprintf(message, "%s(%zu letters)", buffer, len);
    size_of_message = strlen(message);
    printk(KERN_INFO "SimpleChar: Received %zu characters from the user\n", len);
    return len;
}

module_init(simplechar_init);
module_exit(simplechar_exit);
