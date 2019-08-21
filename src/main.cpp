//Library Includes
#include <Arduino.h>
#include <ESP8266WiFi.h>  // Enables the ESP8266 to connect to the local network (via WiFi)
#include <FastLED.h>
FASTLED_USING_NAMESPACE
#include <FirebaseArduino.h>

#include <variables.h>
#include <credentials.h>
#include <methods.h>



void setup() {
  // put your setup code here, to run once:
  setup_wifi();
}

void loop() {
  // put your main code here, to run repeatedly:
}