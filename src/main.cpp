//Library Includes
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <FastLED.h>

FASTLED_USING_NAMESPACE
#define NUM_LEDS 12
#define DATA_PIN 5
CRGB leds[NUM_LEDS];

//my own header files
#include <credentials.h>
#include <methods.h>
#include <position.h>

using namespace std;


const char _no_meal[] = "no meal";
const char _meal[] = "meal";
const char _snacks[] = "snacks";

int no_meal_lights[4] = {0,1,2,3};
int meal_lights[4] = {4,5,6,7};
int snacks_lights[4] = {8,9,10,11};

//(status-name,switch-input-pin, state, led-array-indexes)
Position no_meal((const char*)_no_meal, 14, false, no_meal_lights);
Position    meal((const char*)_meal,    2, false, meal_lights);
Position  snacks((const char*)_snacks,  4, false, snacks_lights);


void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  Serial.begin(1152000);
  Serial.println("Chalmers Signal Booting!");
  delay(2000);
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(128);

  WiFi.begin(ssid, wifi_password);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  no_meal.setup();
  meal.setup();
  snacks.setup();
}
void loop() {
  // put your main code here, to run repeatedly:
  no_meal.loop();
  meal.loop();
  snacks.loop();
}