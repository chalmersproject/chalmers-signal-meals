//Library Includes
#include <Arduino.h>
#include <ESP8266WiFi.h>  // Enables the ESP8266 to connect to the local network (via WiFi)
#include <FastLED.h>

#include <FirebaseArduino.h>
//my own header files
#include <variables.h>
#include <credentials.h>
#include <methods.h>
#include <objects.h>
CRGB leds[NUM_LEDS];
FASTLED_USING_NAMESPACE
void setup() {
  delay(3000);
  setup_wifi();
  setup_firebase();
  setup_leds();
  
  Position no_meal;
  Position meal;  
  Position snacks;

  init_positions(no_meal, [0,1,2,3], false);
  init_positions(meal, [4,5,6,7], false);
  init_positions(snacks, [8,9,10,11], false);
}

void loop() {
  if(check_position_change()){
    //push position to firebase; update LEDs for new position
    position_update(position);
  }
  fast_led_update();
}`