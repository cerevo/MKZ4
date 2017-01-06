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

/* Create a WiFi access point and provide a web server on it. */

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "MKZ4_example2";
const char *password = "";

ESP8266WebServer server(80);
ESP8266WebServer server_8080(8080);

/* set I2C library*/
#include <Wire.h>
#define ADDR1  0x64

#define command_start  0
#define command_stop   1
#define command_back  2
#define forward       0x01
#define reverse       0x02
#define servo_right 110  
#define servo_left  60

#define LED_H       (digitalWrite( 12, HIGH ))
#define LED_L       (digitalWrite( 12, LOW ))

char state = command_stop;
int offset = 0;

String form ="<!DOCTYPE html>"
"<html>"
"<head>"
"<meta name=\"viewport\" content=\"width=device-width, initial-scale=1, minimum-scale=1, maximum-scale=1\">"
"<style>"
"* { padding: 0; margin: 0; }"
"body { background-color: #0097C1; }"
"</style>"
"</head>"
"<body>"
"<div id=\"beta\"></div>"
"<form action=\"\" target=\"tif\" id=\"form\">"
"<iframe src=\"javascript: false;\" style=\"display: none;\" name=\"tif\" id=\"tif\"></iframe>"
"</form>"
"<script>"
"var esp_port = \'http://192.168.4.1:8080\';"
"var el_form = document.getElementById(\'form\');"
"var threshold = 10;"
"var command = \'/stop\';"
"window.addEventListener(\'deviceorientation\', function(event){"
" var y = parseInt(event.gamma);"
" var x = parseInt(event.beta);"
" var url = \'/stop\';"  
      "if (x < (threshold * -1)) {"
         "if(y < (threshold * -1)) {"
             " url = \'/f_left\';"
          "}else if(y > (threshold )){"
            "url = \'/f_right\';"
          "}else{"
              "url = \'/drive\';"
            "}"
        "}else if(x > (threshold )){"
          "if(y < (threshold/2 * -1)) {"
              "url = \'/r_left\';"
          "}else if(y > (threshold/2 )){"
            "url = \'/r_right\';"
          "}else{"
            "url = \'/back\';"
          "}"
        "}else{"
          "if(y < (threshold/2 * -1)) {"
                "url = \'/left\';"
            "}else if(y > (threshold/2 )){"
              "url = \'/right\';"
            "}"
         "}"
        "document.getElementById(\'beta\').innerHTML = event.gamma + \"<br>\" + event.beta + \"<br>\" + url;"
          "if(command!=url){"
                "el_form.action = esp_port + url;"
                "el_form.submit();"
              "}"
              "command = url;"
     " });"
    "</script>"
  "</body>"
"</html>";

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void setup() {
	delay(1000);
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point...");

  Wire.begin(4, 14);
  delay(40);
  
	/* You can remove the password parameter if you want the AP to be open. */
	WiFi.softAP(ssid, password);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
	server.on("/", handleRoot);

  // And as regular external functions:
  server_8080.on("/stop", handle_stop);
  server_8080.on("/drive", handle_drive);
  server_8080.on("/back", handle_back);
  server_8080.on("/left", handle_left);
  server_8080.on("/right", handle_right);
  server_8080.on("/f_left", handle_f_left);
  server_8080.on("/f_right", handle_f_right);
  server_8080.on("/r_left", handle_r_left);
  server_8080.on("/r_right", handle_r_right);
 
	server.begin();
  server_8080.begin();
  
	Serial.println("HTTP server started");
  pinMode(16,OUTPUT);
  pinMode(12,OUTPUT);
  delay(100);
}

void loop() {
	server.handleClient();
  server_8080.handleClient();
}


void handleRoot() {
  server.send(200, "text/html", form);
}


void handle_stop() {
  Serial.print("stop\r\n");
  LED_H;
    stop_motor();
    state = command_stop;
  LED_L;
  server_8080.send(200, "text/html", "");
}

void handle_drive() {
 Serial.print("drive\r\n");
  drive();
  servo_control(90);
  server_8080.send(200, "text/html", "");
}

void handle_back() {
  Serial.print("back\r\n");
  back();
  servo_control(90);
}

void handle_left(){
  Serial.print("left\r\n");
   //drive();
  servo_control(servo_left);
  server_8080.send(200, "text/html", "");
}

void handle_right(){
  Serial.print("right\r\n");
  // drive();
  servo_control(servo_right);
  server_8080.send(200, "text/html", "");
}


void handle_f_left(){
  Serial.print("f_left\r\n");
  drive();
  servo_control(servo_left);
  server_8080.send(200, "text/html", "");
}


void handle_f_right(){
  Serial.print("f_right\r\n");
  drive();
  servo_control(servo_right);
 server_8080.send(200, "text/html", "");
}

void handle_r_left(){
  Serial.print("r_left\r\n");
  back();
  servo_control(servo_left);
  server_8080.send(200, "text/html", "");
}


void handle_r_right(){
  Serial.print("r_right\r\n");
  back();
  servo_control(servo_right);
  server_8080.send(200, "text/html", "");
}

void drive(){
    if(state == command_back){
    
     stop_motor();

     delay(10);

     start_motor();
  
  }else if(state == command_stop){
    start_motor();
  }
  state = command_start;
}

void back(){
    if(state == command_start){
    
     stop_motor();

     delay(10);

     reverse_motor();
  
  }else if(state == command_stop){
    reverse_motor();

  }
  state = command_back;
}

void start_motor(){
  char i, volt;
  volt = 0x20;
  for(i=0;i<5;i++){ 
    volt = volt + ((0x40)*i);
    volt = volt | forward;
    motor_func(ADDR1 , volt);
    delay(10);
  }
}

void reverse_motor(){
    char i, volt;
  volt = 0x20;
  for(i=0;i<5;i++){ 
    volt = volt + ((0x40)*i);
    volt = volt | reverse;
    motor_func(ADDR1 , volt);
    delay(10);
  }
   
}


void stop_motor(){
  motor_func(ADDR1 , 0x18);
  delay(10);

  motor_func(ADDR1 , 0x1B);
  delay(10);
}

void motor_func(char add , char duty){
  Wire.beginTransmission(add);
  Wire.write(0x00);
  Wire.write(duty);
  Wire.endTransmission();
}

void servo_control(int angle){
int microsec,i;

      LED_H;
      microsec = (5*(angle+offset))+ 1000;
       
      for(i=0; i<20 ;i++){
        digitalWrite( 16, HIGH );
        delayMicroseconds( microsec ); 
        digitalWrite( 16, LOW );
        delayMicroseconds( 10000 - microsec ); 
      }

      LED_L;
}

