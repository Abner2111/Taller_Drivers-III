#ifndef GPIO_H
#define GPIO_H
#define PRINT_CONSTANT_NAME(constant) printf(#constant " = %d\n", constant)
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
void gpioSetMode0to7(unsigned int mode);
int gpioGetMode(unsigned int pin);
void gpioWrite(unsigned char bit, unsigned int pin);
void gpioWrite0to7(unsigned char bit);
void gpioInitPtrs();
void  gpioGetMode0to7(int modes[8]);
int  gpioReadValue();
void gpioReadValue0to7(int pinValues[8]); 
#endif