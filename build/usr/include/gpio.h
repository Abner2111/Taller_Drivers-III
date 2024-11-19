#ifndef GPIO_H
#define GPIO_H

#define INPUT 0
#define OUTPUT 1
#define ALT_F_0 4
#define ALT_F_1 5
#define ALT_F_2 6
#define ALT_F_3 7
#define ALT_F_4 3
#define ALT_F_5 2
#define GPIO_BASE 0xfe200000
void gpioSetMode(unsigned int mode,unsigned int pin);
int gpioGetMode(unsigned int pin);
void gpioWrite(unsigned char bit, unsigned int pin);

#endif