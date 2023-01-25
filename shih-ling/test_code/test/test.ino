/*
  Title:        APSC 101 U-1 Module 5 Arduino Program Template
  Date:         Jan 5th, 2023
  Description:  This template includes all necessary headers for the arduino headers, as well as the setup.
                To configure your arduino, see the schematic.pdf or device_connection.png located at the root of this repository.
                Only modify the loop() part of this program. Add new functions as necessary. DO NOT MODIFY THE TEMPLATE.
                Please create a new file to make edits.
 */

#include <NewPing.h>      //NewPing library for ultrasonic sensor
#include <Servo.h>        //servo library for servo motor

Servo myservo;            //create servo object to control servo motor

//Ultrasonic definitions
#define ULTRASONIC_GND      10
#define ULTRASONIC_ECHO     11
#define ULTRASONIC_TRIGGER  12
#define ULTRASONIC_VCC      13
#define MAX_DISTANCE        200                                   //maximum distance set to 200 cm
NewPing sonar(ULTRASONIC_TRIGGER, ULTRASONIC_ECHO, MAX_DISTANCE); //initialize NewPing

//Servo Pin definitions
#define SERVO 9

//Switch Pin definitions
#define SWITCH 8

void setup() {
  //Serial Debug Setup
  Serial.begin(9600);            // set data transmission rate to communicate with computer
  
  //Ultrasonic Setup
  pinMode(ULTRASONIC_ECHO, INPUT);  
  pinMode(ULTRASONIC_TRIGGER, OUTPUT);
  pinMode(ULTRASONIC_GND, OUTPUT);    // tell pin 10 it is going to be an output
  pinMode(ULTRASONIC_VCC, OUTPUT);       // tell pin 13 it is going to be an output
  digitalWrite(ULTRASONIC_GND,LOW);   // tell pin 10 to output LOW (OV, or ground)
  digitalWrite(ULTRASONIC_VCC, HIGH) ;   // tell pin 13 to output HIGH (+5V)

  //Servo Motor Setup
  myservo.attach(SERVO);  // attaches the servo on pin 9 to the servo object}

  //Switch Setup
  pinMode(SWITCH, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);                             // wait for this number of milliseconds
  int DISTANCE_IN_CM = sonar.ping_cm();   // read the sonar sensor, using a variable
  Serial.print("Ping: ");                 //print “Ping:" on the computer display
  Serial.print(DISTANCE_IN_CM);           //print the value of the variable next
  Serial.println("cm");                   //print "cm" after that, then go to next lin

  if (DISTANCE_IN_CM <= 15 && digitalRead(8) == HIGH) {
    myservo.write(0);
  }
  else {
    myservo.write(180);
  }
}