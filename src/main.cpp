//Library Includes
#include <Arduino.h>
#include <ESP8266WiFi.h>  // Enables the ESP8266 to connect to the local network (via WiFi)
#include <FastLED.h>
FASTLED_USING_NAMESPACE
#include <FirebaseArduino.h>
//my own header files
#include <variables.h>
#include <credentials.h>
#include <methods.h>

CRGB leds[NUM_LEDS];

void setup() {
  delay(3000);
  setup_wifi();
  setup_firebase();
  setup_leds();
}

void loop() {
  if(check_position_change()){
    //push position to firebase; update LEDs for new position
    position_update(position);
  }
  fast_led_update();
}