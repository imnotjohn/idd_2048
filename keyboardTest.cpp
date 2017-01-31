#include "mbed.h"
#include "USBKeyboard.h"
 
//LED1: NUM_LOCK
//LED2: CAPS_LOCK
//LED3: SCROLL_LOCK
BusOut leds(LED1, LED2, LED3);
 
//USBKeyboard
USBKeyboard keyboard;
 
int main(void) {
    while (1) {
        keyboard.printf("w\r");
        wait(1);
    }
}