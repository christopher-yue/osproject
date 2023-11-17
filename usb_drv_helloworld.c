#include <linux/module.h>
#include <linux/init.h>
#include <linux/usb.h>

/* Meta Information */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Christopher Yue");
MODULE_DESCRIPTION("Basic driver for macropad");

// vendor and product id of device
#define VENDOR_ID 0x045e
#define PRODUCT_ID 0x02e3

// defines what devices this driver will be for
static struct usb_device_id usb_dev_table [] = {
    { USB_DEVICE(VENDOR_ID, PRODUCT_ID) },
    {},
};
MODULE_DEVICE_TABLE(usb, usb_dev_table);

static int my_usb_probe(struct usb_interface *intf, const struct usb_device_id *id) {
    printk("my_usb_devdrv - Probe Function\n");
    return 0;
}

// called when usb device is disconnected
static void my_usb_disconnect(struct usb_interface *intf) {
    printk("my_usb_devdrv - Disconnect Function\n");
}

static struct usb_driver my_usb_driver = {
    .name = "my_usb_devdrv",
    .id_table = usb_dev_table,
    .probe = my_usb_probe,
    .disconnect = my_usb_disconnect,
};

// called when module is loaded into kernel
static int __init my_init(void) {
    int result;
    printk("my_usb_devdrv - Init Function\n");
    result = usb_register(&my_usb_driver);
    if(result) {
        printk("my_usb_devdrv - Error during register!\n");
        return -result;
    }

    return 0;
}

// called when module is removed from the kernel
static void __exit my_exit(void) {
    printk("my_usb_devdrv - Exit Function\n");
    usb_deregister(&my_usb_driver);
}

module_init(my_init);
module_exit(my_exit);