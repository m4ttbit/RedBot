// We are using the RedBot library for the accelerometer code
#include "RedBot.h"
RedBotAccel xl;

// setting motor pins as variables
int motorafb = 2;
int motorab = 4;
int motorahs = 5;
int motorbfb = 7;
int motorbb = 8;
int motorbhs = 6;

void setup() {
	
	//Setup Motor Channel A
	pinMode(motorafb, OUTPUT); //Initiates  pin
	pinMode(motorab, OUTPUT); //Initiates Brake Motor Channel A pin
	
	//Setup Motor Channel B
	pinMode(motorbfb, OUTPUT); //Initiates  pin
	pinMode(motorbb, OUTPUT);  //Initiates Brake Motor Channel A pin
	
	// This is the bit to enable the accelerometer using the RedBot library
	xl.enableBump();
	xl.setBumpThresh(70);
}

void loop(){
	// this if statement checks to see if its been bumped, and if it has, it runs the commands inside the {}
	if (xl.checkBump()) {
		
		digitalWrite(motorab, HIGH);  //Engage the Brake for Motor Channel A
		digitalWrite(motorbb, HIGH);  //Engage the Brake for Motor Channel B
		delay(500);
		//Motor A reversing @ full speed
		digitalWrite(motorafb, LOW);  //Establishes backward direction of Motor Channel A
		digitalWrite(motorab, LOW);   //Disengage the Brake for Motor Channel A
		analogWrite(motorahs, 255);    //Spins the motor on Motor Channel A at half speed
		
		//Motor B reversing @ full speed
		digitalWrite(motorbfb, LOW); //Establishes forward direction of Motor Channel B
		digitalWrite(motorbb, LOW);   //Disengage the Brake for Motor Channel B
		analogWrite(motorbhs, 255);   //Spins the motor on Motor Channel B at full speed
		
		delay(1000);
		
		//Motor A reversing @ half speed
		digitalWrite(motorafb, LOW);  //Establishes backward direction of Motor Channel A
		digitalWrite(motorab, LOW);   //Disengage the Brake for Motor Channel A
		analogWrite(motorahs, 155);    //Spins the motor on Motor Channel A at half speed
		
		//Motor B forward @ full speed
		digitalWrite(motorbfb, HIGH); //Establishes forward direction of Motor Channel B
		digitalWrite(motorbb, LOW);   //Disengage the Brake for Motor Channel B
		analogWrite(motorbhs, 255);   //Spins the motor on Motor Channel B at full speed
		
		delay(500);
		
	} else // This is what happens if nothing has been bumped into
	{
		// both motors full speed
		//Motor A forward @ full speed
		digitalWrite(motorafb, HIGH); //Establishes forward direction of Motor Channel A
		digitalWrite(motorab, LOW);   //Disengage the Brake for Motor Channel A
		analogWrite(motorahs, 255);   //Spins the motor on Motor Channel A at full speed
		
		//Motor B foward @ full speed
		digitalWrite(motorbfb, HIGH);  //Establishes backward direction of Motor Channel B
		digitalWrite(motorbb, LOW);   //Disengage the Brake for Motor Channel B
		analogWrite(motorbhs, 255);    //Spins the motor on Motor Channel B at half speed
		
		//delay(1000);
		// STOP!
		
		digitalWrite(motorab, HIGH);  //Engage the Brake for Motor Channel A
		digitalWrite(motorbb, HIGH);  //Engage the Brake for Motor Channel B
		analogWrite(motorahs, 0); // Set speed to 0
		analogWrite(motorbhs, 0);// Set speed to 0
		
		delay(500);
		
		//Turn right
		//Motor A forward @ full speed revering
		digitalWrite(motorafb, LOW);  //Establishes backward direction of Motor Channel A
		digitalWrite(motorab, LOW);   //Disengage the Brake for Motor Channel A
		analogWrite(motorahs, 155);    //Spins the motor on Motor Channel A at half speed
		
		//Motor B forward @ full speed
		digitalWrite(motorbfb, HIGH); //Establishes forward direction of Motor Channel B
		digitalWrite(motorbb, LOW);   //Disengage the Brake for Motor Channel B
		analogWrite(motorbhs, 255);   //Spins the motor on Motor Channel B at full speed
		
		delay(255);
		
		digitalWrite(motorab, HIGH);  //Engage the Brake for Motor Channel A
		digitalWrite(motorbb, HIGH);  //Engage the Brake for Motor Channel B
		
		delay(3000);
	}
}
