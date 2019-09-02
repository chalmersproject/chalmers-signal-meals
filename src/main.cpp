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



#include <Arduino.h>
#include <ESP8266WiFi.h>  // Enables the ESP8266 to connect to the local network (via WiFi)
#include <FastLED.h>
#include <FirebaseArduino.h>
using namespace std;

class Position
{
    int switch_pin;
    bool current_state;
    unsigned long time_since_change;
    int lights_positions[4];
    const char* status_name;

    public:
    Position(const char* name, int pin, bool state, int* lights)
    {
      status_name = name;

      switch_pin = pin;
      pinMode(switch_pin, INPUT_PULLUP);

      current_state = state;
      for (int i = 0; i < 4; i++)
      {
        lights_positions[i] = lights[i];
      }
    }
};

//(status-name,switch-input-pin, state, led-array-indexes)
// int no_meal_array[4] = {4,5,6,7};
Position no_meal("no_meal", 12, false, {4,5,6,7});
// Position    meal("meal",    12, false, {4,5,6,7});
// Position  snacks("snacks",  12, false, {4,5,6,7});

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}
void setup() {
  delay(3000);
  setup_wifi();
  setup_firebase();
  setup_leds();
}

void loop() {
  // if(check_position_change()){
  //   //push position to firebase; update LEDs for new position
  //   position_update(position);
  // }
  fast_led_update(1000);
}