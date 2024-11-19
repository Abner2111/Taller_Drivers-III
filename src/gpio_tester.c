#include "gpio.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    // Initialize GPIO pointers
    gpioInitPtrs();

    // Test gpioSetMode and gpioGetMode
    printf("Setting GPIO pins 0-7 to OUTPUT mode...\n");
    gpioSetMode0to7(OUTPUT);
    for (int i = 0; i < 8; i++) {
        gpioGetMode(i); // Print each pin's mode
    }

    // Test gpioWrite and gpioReadValue
    printf("Toggling GPIO pins 0-7...\n");
    gpioWrite0to7(1); // Set pins 0-7
    usleep(500000);   // Wait 0.5 seconds
    int pinValues[8];
    gpioReadValue0to7(pinValues); // Read and print pin values
    gpioWrite0to7(0); // Clear pins 0-7
    usleep(500000);   // Wait 0.5 seconds
    gpioSetMode0to7(INPUT); //set to input
    gpioReadValue0to7(pinValues); // Read and print pin values again

    // Test single pin operations
    printf("Testing GPIO pin 3...\n");
    gpioSetMode(OUTPUT, 3); // Set pin 3 as OUTPUT
    gpioWrite(1, 3);        // Set pin 3
    usleep(1000000);        // Wait 1 second
    gpioSetMode(INPUT, 3);  //set pin 3 as INPUT
    gpioReadValue(3);       // Read and print value of pin 3
    gpioSetMode(OUTPUT, 3); // Set pin 3 as OUTPUT
    gpioWrite(0, 3);        // Clear pin 3
    gpioReadValue(3);       // Read and print value of pin 3 again

    return 0;
}
