
//include the redbot library to get the functions out of the library
#include <RedBot.h>

RedBotMotors motors;

void setup()
{
  Serial.begin(9600);//This will open the serial port to send values out to calibrate sensors
 
}

int x = 0;

void loop()
{
	if (x < 4)
	{
		motors.drive(127);
		delay(1000);
		motors.pivot(127);
		delay(700);
	}
	x++;
	if (x >= 4)
	{
		motors.brake();
	}
}

