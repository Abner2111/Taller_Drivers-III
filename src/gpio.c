#include <sys/mman.h> //mmap
#include <err.h> //error handling
#include <fcntl.h> //file ops
#include <unistd.h> //usleep
#include "gpio.h"
#include <string.h>
#include <stdio.h>
//Registers pointers
volatile unsigned int * gpfsel0;
volatile unsigned int * gpset0;
volatile unsigned int * gpclr0;
volatile unsigned int * gplev0;


// Initialize pointers: performs memory mapping, exits if mapping fails
void gpioInitPtrs(){
	int fd = -1;
	//Loading /dev/mem into a file
	if ((fd = open("/dev/mem", O_RDWR, 0)) == -1)
            err(1, "Error opening /dev/mem");

    //Mapping GPIO base physical address 
	gpfsel0 = (unsigned int*)mmap(0, getpagesize(), PROT_WRITE, MAP_SHARED, fd, GPIO_BASE);

	//Check for mapping errors
	if (gpfsel0 == MAP_FAILED)
		errx(1, "Error during mapping GPIO");
	
	//Set registers pointers
	gpset0 = gpfsel0 + 0x7; // offset 0x1C / 4 = 0x7
	gpclr0 = gpfsel0 + 0xA; // offset 0x28 / 4 = 0xA
	gplev0 = gpfsel0 + 0xD; // offset 0x34 / 4 = 0xD
}
//Sets GPIOX as output 
void gpioSetMode(unsigned int mode,unsigned int pin){
	if (mode < 8 && pin <8){
		*gpfsel0 = (*gpfsel0) & (0xFFFFFFFF ^ (0X7<<(pin*3)));
		*gpfsel0 = *gpfsel0 | (mode<<(pin*3)); //0 0100 0000
	}
	
}

void gpioSetMode0to7(unsigned int mode)
{
	*gpfsel0 = 0x0;	
	*gpfsel0 = *gpfsel0 | 0x249249; //0 0100 0000
}
void  gpioGetMode0to7(int modes[8]){
	for (int i = 0; i<8; i++){
		modes[i]=gpioGetMode(i);
	}
}
int gpioReadValue(int pin)
{
    int pinValue = (*gplev0 & (0x1 << pin))>>pin;
	return pinValue;
}
void gpioReadValue0to7(int pinValues[8])
{
	
    for(int i = 0; i<8; i++){
		pinValues[i] = gpioReadValue(i);
		printf("Value of pin %d: %d", i, pinValues[i]);
	}
}
int gpioGetMode(unsigned int pin)
{
    unsigned int mode;
	char mode_s[8];
	mode = (*gpfsel0 & (0x7 << pin)) >> pin;
	switch (mode)
	{
	case INPUT:
		strcpy(mode_s, "INPUT");
		break;
	case OUTPUT:
		strcpy(mode_s, "OUTPUT");
		break;
	case ALT_F_0:
		strcpy(mode_s, "ALT_F_0");
		break;
	case ALT_F_1:
		strcpy(mode_s, "ALT_F_1");
		break;
	case ALT_F_2:
		strcpy(mode_s, "ALT_F_2");
		break;
	case ALT_F_3:
		strcpy(mode_s, "ALT_F_3");
		break;
	case ALT_F_4:
		strcpy(mode_s, "ALT_F_4");
		break;
	case ALT_F_5:
		strcpy(mode_s, "ALT_F_5");
		break;
	default:
		strcpy(mode_s, "UNKNOWN");
		break;
	}
	printf("Mode of pin %d is %s\n", pin, mode_s);
	return mode;
}


//Writes to GPIOX
void gpioWrite(unsigned char bit, unsigned int pin){
	if (bit) *gpset0 = (0x1 << pin); //sets bit
	else *gpclr0 = (0x1 << pin); //clears bit
}

void gpioWrite0to7(unsigned char bit)
{
	if (bit) *gpset0 = 0xff; //sets bit 0-7
	else *gpclr0 = 0xff; //clears bit 0-7
}

