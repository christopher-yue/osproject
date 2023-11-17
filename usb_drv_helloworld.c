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

// called when device is installed that the USB core thinks this driver should handle
static int my_usb_probe(struct usb_interface *intf, const struct usb_device_id *id) {
    printk("usb_drv - Probe Function\n");
    return 0;
}

// called when the driver should no longer control the device
static void my_usb_disconnect(struct usb_interface *intf) {
    printk("usb_drv - Disconnect Function\n");
}

// describes the USB driver to the USB core
static struct usb_driver my_usb_driver = {
    .name = "usb_drv_helloworld",
    .id_table = usb_dev_table,
    .probe = my_usb_probe,
    .disconnect = my_usb_disconnect,
};

// called when module is loaded into kernel
static int __init my_init(void) {
    int result;
    printk("usb_drv - Init Function\n");
    result = usb_register(&my_usb_driver);
    if(result) {
        printk("usb_drv - Error during register!\n");
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