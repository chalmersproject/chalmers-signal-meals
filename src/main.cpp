//Library Includes
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <FastLED.h>
#include <FirebaseArduino.h>

//my own header files
#include <credentials.h>
#include <methods.h>
#include <objects.h>

FASTLED_USING_NAMESPACE
#define NUM_LEDS 12
#define DATA_PIN 5
CRGB leds[NUM_LEDS];

using namespace std;

const char _no_meal[] = "no meal";
const char _meal[] = "meal";
const char _snacks[] = "snacks";

int no_meal_lights[4] = {0,1,2,3};
int meal_lights[4] = {4,5,6,7};
int snacks_lights[4] = {8,9,10,11};

//(status-name,switch-input-pin, state, led-array-indexes)
Position no_meal((const char*)_no_meal, 12, false, no_meal_lights);
Position    meal((const char*)_meal,    13, false, meal_lights);
Position  snacks((const char*)_snacks,  14, false, snacks_lights);


void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  delay(2000);
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  //setup_wifi();
  //setup_firebase();
}
void loop() {
  // put your main code here, to run repeatedly:
}