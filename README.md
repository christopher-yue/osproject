# Linux macropad driver project

## Macropad
- GOWENIC 6 Key Macro Pad, OSU Keypad Mini Gaming Keypad with Knob USB DIY Programmable Keyboard OSU Keyboard for Gaming Office
- https://www.amazon.com/dp/B0B8HRN7RQ?psc=1&ref=ppx_yo2ov_dt_b_product_details

## How to insert module into kernel
- create makefile
  ```obj-m = [filename].o
  all:
    make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
  clean:
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean```
- run the make command in the terminal
- run `sudo insmod [filename].ko` in terminal
