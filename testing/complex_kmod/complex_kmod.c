#include <linux/init.h>
#include <linux/module.h>
#include "helper.h"


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A more complicated Linux char driver for testing C++ integration");
MODULE_VERSION("0.1");

static int __init complexchar_init(void) {
    printk(KERN_INFO "ComplexChar: Initializing and making a C++ call\n");

    // Call the C++ function
    size_t result = cpp_initialization();
    printk(KERN_INFO "ComplexChar: C++ call returned: %zu\n", result);

    return 0; // Indicate successful initialization
}

static void __exit complexchar_exit(void) {
    size_t result = cpp_destruction();
    printk(KERN_INFO "ComplexChar: Exiting\n");
}

module_init(complexchar_init);
module_exit(complexchar_exit);
