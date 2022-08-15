/*
 * Copyright (c) 2015, Majenko Technologies
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 * 
 * * Neither the name of Majenko Technologies nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include <ESP8266WiFi.h>
#include <Servo.h>

/* set I2C library*/
#include <Wire.h>
#define ADDR1 0x64
#define REG0 0x00

Servo servo;

#define FORWARD       0x01
#define REVERSE       0x02

#define SERVO_CENTRE 80
#define SERVO_DIVERSION_MAX 20 

#define MOTOR_STOP_THRESHOLD 0x9

#define MINSPEED 0x06
#define MAXSPEED 0x20
#define MOTOR_RELEASE 0x18
#define MOTOR_BRAKE 0x1B

#define SERVO_PIN 16
#define LED_PIN 12

#define LED_H       (digitalWrite( LED_PIN, HIGH ))
#define LED_L       (digitalWrite( LED_PIN, LOW ))

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();

  Wire.begin(4, 14);
  delay(40);

  servo.attach(SERVO_PIN);
  pinMode(LED_PIN,OUTPUT);

  LED_H;
  
  set_steering(0);
}

String inputString = "";     // a String to hold incoming data
bool stringComplete = false; // whether the string is complete


void loop() {
  if (stringComplete)
  {
#ifdef DEBUG_RESPONSE
    Serial.print("Res:");
    Serial.println(inputString);
#endif

    const char *inputStr = inputString.c_str();
    char * header = strstr(inputStr, "A");
    if(header != NULL){
      char *beforeComma = strtok((char *)(inputStr + 1), ",");
      char *afterComma = strtok(NULL, ",");
      if (beforeComma != NULL && afterComma != NULL)
      {
        int angle = atoi(beforeComma);
        int speed = atoi(afterComma);
        speed *= -1;

#ifdef DEBUG_RESPONSE
        Serial.print("Speed: ");
        Serial.print(speed);
        Serial.print(" Angle: ");
        Serial.println(angle);
#endif
        drive_motor(speed);
        set_steering(angle);
      }
    }

    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent()
{
  while (Serial.available())
  {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n')
    {
      stringComplete = true;
    }
  }
}

// speed -100 ~ 100
void drive_motor(int speed){
  int absSpeed = abs(speed);
  if (absSpeed > MOTOR_STOP_THRESHOLD)
  {
    set_motor_speed(speed);
  }
  else{
    stop_motor();
  }
}


void set_motor_speed(int speed){
  // char i, volt;
  int absSpeed = abs(speed);
  uint8_t volt = map(absSpeed, 0, 100, MINSPEED, MAXSPEED);
  volt = volt << 2;
  
  if(speed > 0){
    volt = volt | FORWARD;
  }
  else{
    volt = volt | REVERSE;
  }
  motor_func(ADDR1 , volt);
}

void stop_motor(){
  motor_func(ADDR1, MOTOR_RELEASE);
  delay(10);
  motor_func(ADDR1, MOTOR_BRAKE);
  delay(10);
}

void motor_func(char add , char duty){
  Wire.beginTransmission(add);
  Wire.write(REG0);
  Wire.write(duty);
  Wire.endTransmission();
}

void set_steering(int steer){
  int servoVal = map(steer, -100, 100, SERVO_CENTRE - SERVO_DIVERSION_MAX, SERVO_CENTRE + SERVO_DIVERSION_MAX);
  servo.write(servoVal);
}
