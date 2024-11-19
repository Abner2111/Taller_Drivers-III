#include "gpio.h"

int main(int argc, char const *argv[])
{
	gpioInitPtrs();
	gpioSetMode(OUTPUT, 3);

	//toggle GPIO2
	gpioWrite(1,3);
	usleep(1000000);
	gpioWrite(0,3);
	
	return 0;
}