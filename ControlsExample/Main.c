#include <RASLib/inc/common.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/pid.h>

// Blink the LED to show we're on
tBoolean blink_on = true;

//variables for PID control
tPID* example;  //pid module
float k_p = 0;
float k_i = 0;
float k_d = 0;

void blink(void) {
    SetPin(PIN_F3, blink_on);
    blink_on = !blink_on;
}


// The 'main' function is the entry point of the program
int main(void) {
    example = InitializePID(k_p, k_i, k_d);

    // Initialization code can go here
    CallEvery(blink, 0, 0.5);

    while (1) {
        // Runtime code can go here
        Printf("Hello World!\n");

    }
}
