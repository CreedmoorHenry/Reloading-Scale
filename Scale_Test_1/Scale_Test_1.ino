
//servo
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int Open = 0;
int Close = 180; //180 max range
int servo = 2; //servo pin

//stepper motor
#include <Stepper.h>
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); // initialize the stepper library 


//Dispaly
#include "LCDIC2.h"
LCDIC2 lcd(0x27, 16, 2);

//Scale
#include "HX711.h"
// HX711 circuit wiring
const int DOUT_PIN = 4;
const int SCK_PIN = 3;
HX711 scale;


void setup() {
  myservo.attach(servo); // attaches the servo
  scale.begin(DOUT_PIN, SCK_PIN);
  lcd.setCursor ( 0, 0 );                   // go home
  lcd.print("Hello, ARDUINO ");  
  lcd.setCursor ( 0, 1 );        // go to the next line
  lcd.print (" WORLD!  "); 
  
}

void loop() {
    int sensorReading = analogRead(A0);
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution / 100);
  // put your main code here, to run repeatedly:
  }
}
