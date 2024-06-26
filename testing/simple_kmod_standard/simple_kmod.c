#include <linux/init.h>
#include <linux/module.h>



MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Linux char driver for testing C++ integration");
MODULE_VERSION("0.1");

static int __init simplechar_init(void) {
    printk(KERN_INFO "SimpleChar: Initializing and making a C++ call\n");

    // Call the C++ function
    //size_t result = helper_function();
    //printk(KERN_INFO "SimpleChar: C++ call returned: %zu\n", result);

    return 0; // Indicate successful initialization
}

static void __exit simplechar_exit(void) {
    printk(KERN_INFO "SimpleChar: Exiting\n");
}

module_init(simplechar_init);
module_exit(simplechar_exit);
