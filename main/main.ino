/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 * This example runs directly on ESP8266 chip.
 *
 * Note: This requires ESP8266 support package:
 *   https://github.com/esp8266/Arduino
 *
 * Please be sure to select the right ESP8266 module
 * in the Tools -> Board menu!
 *
 * Change WiFi ssid, pass, and Blynk auth token to run :)
 *
 **************************************************************/

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>


Servo servoX, servoY;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

int servoXval = 90, servoYval = 90;


BLYNK_WRITE(V1) { //use V1 in blynk for sending joystick data
  int x = param[1].asInt();
  int y = param[0].asInt();

  // Do something with x and y
  Serial.print("X = ");
  Serial.print(x);
  Serial.print("; Y = ");
  Serial.println(y);

  servoXval = map(x, 0, 1023, 120, 10); //scale and limit joystick input from blynk app
  servoYval = map(y, 0, 1023, 10, 180);

  delay(20);
  servoX.write( servoXval );
  delay(20);
  servoY.write( servoYval );
}

void setup()
{
  Serial.begin(9600);
  servoX.attach(D0);
  servoY.attach(D1);
  
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}

