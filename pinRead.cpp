// Reading Digital Pins
#include "mbed.h"

/*
// Analog Read Pin
AnalogIn p1(A0);
AnalogIn p2(A1);

//LED
DigitalOut led(LED1);

// Read & Write Serial
Serial pc(USBTX, USBRX);

int main() {
	while(1)
	{	
	p1.read();
	p2.read();
	pc.printf("Pin A0: %f \t Pin A1: %f \r\n", p1,p2);
	}
}
*/

Serial pc(USBTX, USBRX);
AnalogIn Ain(A0);
float ADCdata;

int main() {
    
	pc.printf("ADC Data Values... \n\r");
    
	while (1) 
	{
ADCdata=Ain;
pc.printf("%f \n\r",ADCdata);
wait (0.5);
	}
}