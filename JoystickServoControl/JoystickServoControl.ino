#include <Servo.h>

//const int stbPin = 8;  //the segment display module STB pin connected to digital pin 7
//const int clkPin = 6;  //the segment display module CLK pin connected to digital pin 9
//const int dioPin = 7;  //the segment display module DIO pin connected to digital pin 8
//int digit = 0;            //segment display value


//Servo objects created to control the servos
Servo myServo1;
Servo myServo2;
Servo myServo3;

int servo1 = 3; //Digital PWM pin used by the servo 1
int servo2 = 5; //Digital PWM pin used by the servo 2
int servo3 = 9;
int joyX = 0;   //Analog pin to which the joystick (X) is connected
int joyY = 1;   //Analog pin to which the joystick (Y) is connected
int buttonPin = 8;
int buttonState = 0;

void sendCommand(uint8_t value) 
{ 
//   digitalWrite(stbPin, LOW);                   //pin low.  To begin receiving data
//   shiftOut(dioPin, clkPin, LSBFIRST, value);   //send data(value) to the segment display module
//   digitalWrite(stbPin, HIGH);                  //pin high.  Stop receiving data
}  

void setup(){
  myServo1.attach(servo1);
  myServo2.attach(servo2);
  myServo3.attach(servo3);
  pinMode(buttonPin, INPUT_PULLUP);
  
//  pinMode(stbPin, OUTPUT); //initialize the stbPin as an output
//  pinMode(clkPin, OUTPUT); //initialize the clkPin as an output
//  pinMode(dioPin, OUTPUT); //initialize the dioPin as an output
//  sendCommand(0x8f);       //activate 
}

void loop(){
  buttonState = digitalRead(buttonPin);

  int valX = analogRead(joyX); //Read the joystick X value (value between 0 and 1023)
  int valY = analogRead(joyY); //Read the joystick Y value (value between 0 and 1023)

  valX = map(valX, 0, 1023, 40, 90); //Scale the joystick X value to use it with the servo
  valY = map(valY, 0, 1023, 0, 180); //Scale the joystick X value to use it with the servo

  //Sets the servo position according to the scaled values.
  myServo1.write(valX);   
  myServo2.write(valY);

  if (buttonState == 0) {
    myServo3.write(60);
  } else {
    myServo3.write(0);
  }

//  number();
//  digit = valX;
  
  delay(20);
}

//bool number() {
//  uint8_t digits[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };
//  sendCommand(0x40);                                       //setting the Write Data Command,using automatic address genuine.
//   digitalWrite(stbPin, LOW);                               //pin low.  To begin receiving data
//   shiftOut(dioPin, clkPin, LSBFIRST, 0xc0);                //Set the start address 0C0H
//   shiftOut(dioPin, clkPin, LSBFIRST, digits[digit/1000%10]);//thousand data
//   shiftOut(dioPin, clkPin, LSBFIRST, 0x00);                //filling high 8-bit data               
//   shiftOut(dioPin, clkPin, LSBFIRST, digits[digit/100%10]); //hundred data
//   shiftOut(dioPin, clkPin, LSBFIRST, 0x00);                //filling high 8-bit data 
//   shiftOut(dioPin, clkPin, LSBFIRST, digits[digit/10%10]);  //ten data
//   shiftOut(dioPin, clkPin, LSBFIRST, 0x00);                //filling high 8-bit data 
//   shiftOut(dioPin, clkPin, LSBFIRST, digits[digit%10]);     //bit data
//   shiftOut(dioPin, clkPin, LSBFIRST, 0x00);                //filling high 8-bit data 
//   digitalWrite(stbPin, HIGH);                              //pin high.  Stop receiving data
//   return 0; 
//}
