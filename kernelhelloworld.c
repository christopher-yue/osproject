#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

/* Meta Information */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Christopher Yue");
MODULE_DESCRIPTION("A simple hello world LKM");

/* Called when module is loaded into the kernel */
static int __init hello_start(void) {
    printk("Hello world!\n");
    return 0;
}

/* Called when module is removed from the kernel */
static void __exit hello_end(void) {
    printk("Goodbye!\n");
}

module_init(hello_start);
module_exit(hello_end);