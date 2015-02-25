// Include the libraries.
#include <RedBot.h>

// Instantiate the motor control class. This only needs to be done once
//  and indeed SHOULD only be done once!
RedBotMotor motor;

// Instantiate the accelerometer. It can only be connected to pins A4
//  and A5, since those are the I2C pins for this board.
RedBotAccel xl;

// Create a software serial connection. See the Arduino documentation
//  for more information about this. A "RedBotSoftwareSerial" object allows us
//  to omit the pin description, since the pins are limited by hardware. It also
//  makes provisions for multiplexing pin change interrupts between the
//  SoftwareSerial pins and other functions.
RedBotSoftwareSerial xbee;

void setup()
{
	Serial.begin(57600);
	xbee.begin(57600);
	
	// Enable bump detection. Once a bump occurs, xl.checkBump() can be
	//  used to detect it. We'll use that to start moving.
	xl.enableBump();
}

// Variable used to wait on a bump before starting operation.
boolean go = false;

void loop()
{
	// checkBump() checks a register in the accelerometer to see if a
	//  bump has happened since the last time checkBump() was run. If
	//  one HAS occurred (i.e., the user tapped the accelerometer),
	//  start following the line!
	if  (xl.checkBump() && go == false) go = true;

	if (go)
	{
		motor.drive(-50);
	}
}
void bump()
{
	motors.brake();
	bumped = true;
}

