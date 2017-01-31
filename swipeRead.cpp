// Reading Digital Pins
#include "mbed.h"
#include "USBKeyboard.h"

// Analog Read Pin
AnalogIn p1(PTE20);     //up
AnalogIn p2(PTE21);     //down
//AnalogIn p3(PTE22);   //right
//AnalogIn p4(PTE23);   //left

// Floats
float f1;       //up
float f2;       //down
//float f3;     //right
//float f4;     //left

// Integers
int counter;

// Read & Write Serial
//Serial pc(USBTX, USBRX);

//USBKeyboard
USBKeyboard keyboard;

BusOut led(LED3);

int main() {

    // floats for voltage drop values based on light in my room:
    // Ambient Range: 0.4 - 0.65
    // Covered Range: 0.1 - 0.3
    // floats for voltage drop values based on light in invention lab:
    // Ambient Range: 0.6 - 0.9
    // Covered Range: 0.3 - 0.5
    float covered = 0.3; // maximum value to be considered covered
    float opened = 0.5; // minimum value to be considered open (ambient)
    
	// boolean variables for different wait states
    bool waitingUP;
    bool waitingDOWN;
	//bool waitingRIGHT;
	//bool waitingLEFT;
    
    while(1)
    {   
	
	// Counts amount of time available to read each state
	counter++;
		
	// Read in float value from Analog Pins p1,p2,p3,p4
    p1.read_u16();    //up
    p2.read_u16();    //down
    //p3.read_u16();    //right
    //p4.read_u16();    //left
    
	//Assign voltage values to floats f1,f2,f3,f4
    f1 = p1; //up
    f2 = p2; //down
    //f3 = p4; //right
    //f4 = p4; //left
    
    // LISTENING FOR UP & DOWN SWIPES
    if (p1 < covered && p2 > opened)
    {   
        if (waitingUP)
        {
            //pc.printf("Swiped UP \r\n");
            keyboard.printf("w\r");
            counter = 0;
            waitingUP = false;
            wait(0.2);
        }
            else
            {
                waitingDOWN = true;
                //pc.printf("Waiting to Swipe Down \r\n");
				keyboard.printf("Waiting to Swipe Down\r");
            }
        }

        else if (p2 < covered && p1 > opened)
        {
            if (waitingDOWN)
            {
                //pc.printf("Swiped DOWN \r\n");
				keyboard.printf("s\r");
                counter = 0;
                waitingDOWN = false;
                wait(0.2);
            }
                else
                {
                    waitingUP = true;
                    //pc.printf("Waiting to Swipe Up \r\n");
					keyboard.printf("Waiting to Swipe Up\r");
                }
            }
    
	/*
    // LISTENING FOR LEFT & RIGHT SWIPES
	//Swipe Right -> Left
    if (p3 < covered && p4 > opened)
    {   
        if (waitingRIGHT)
        {
            //pc.printf("Swiped RIGHT \r\n");
            keyboard.printf("e\r");
            counter = 0;
            waitingRIGHT = false;
            wait(0.2);
        }
            else
            {
                waitingLEFT = true;
                //pc.printf("Waiting to Swipe LEFT \r\n");
				keyboard.printf("Waiting to Swipe Left\r");
                counter++;
            }
        }

        else if (p4 < covered && p3 > opened)
        {
            if (waitingLEFT)
            {
                //pc.printf("Swiped LEFT \r\n");
				keyboard.printf("w\r");
                counter = 0;
                waitingLEFT = false;
                wait(0.2);
            }
                else
                {
                    waitingRIGHT = true;
                    //pc.printf("Waiting to Swipe RIGHT \r\n");
					keyboard.printf("Waiting to Swipe Right\r");
                    counter++;
                }
            }
			*/
    
    if (counter > 20)
    {
        waitingUP = false;
        waitingDOWN = false;
        counter = 0;
        //printf("Counter Reset \r\n");
    }
    
    //pc.printf("Pin A0: %f \t Pin A1: %f \r\n", f1,f2);
    //add:
    //pc.printf("%f\n", f1);
    wait(0.2);
    }
    
    //need to add code for condition for "only one cell should be dimmed at a time"
} 