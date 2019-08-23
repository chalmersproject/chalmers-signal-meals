//instatiate the Wifi Client

WiFiClient wifiClient;

void setup_wifi()
{
    delay(10);
    // We start by connecting to a WiFi network
        Serial.println();
        Serial.print("Connecting to ");
        Serial.println(ssid);
    WiFi.begin(ssid, wifi_password);

    //infinite loop unti it connects to Wifi
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void setup_firebase()
{
    // Firebase.begin()
}
void setup_leds()
{
    FastLED.addLeds<LED_TYPE, LED_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(BRIGHTNESS);  
}

int check_position()
{
  for(int i = 0; i < sizeof(switches); i++)
  {
    if(digitalRead(switches[i]))
    {
      //debounce the switch
      delay(240);
      //then recheck
      if(digitalRead(switches[i]))
      {
        position = switches[i];
      }
    }
  }
}

bool check_position_change(){
  check_position();
  if(last_position != position)
  {
      last_position = position;
      return true;
  }
  else{
    return false;
  }
}

void position_update(int position)
{
  //set color for position
  //set message for position
  switch (position){
      case switch_0 :
        color = "none";
        hue_sine_center = 50;
        for (int i = 0; i > 3; i++){led_range[i] = leds[0 + i];}
        message = "n/a";
        break;
      case switch_1 :
        message = "no meal";
        color = "red";
        break;
      case switch_2 :
        message = "meal";
        color = "green";
        break;
      case switch_3 :
        message = "snacks";
        color = "yellow";
        break;
  }
  //update neopixels to "push in progress"
  EVERY_N_MILLISECONDS( 200 )
  {
    bool _switch = (led_switch = 1 / -1 ? HIGH : LOW);
    digitalWrite();
    led_switch *= -1;
  }
  //push updated json to firebase
  //wait for push "success"
  //update neopixels to "push success"
}

void fast_led_update()
{
  // send the 'leds' array out to the actual LED strip    
  FastLED.show();  
  // insert a delay to keep the framerate modest
  FastLED.delay(1000/FRAMES_PER_SECOND); 

  // do some periodic updates
//   EVERY_N_MILLISECONDS( 20 ) { gHue++; } // slowly cycle the "base color" through the rainbow
//   EVERY_N_SECONDS( 10 ) { nextPattern(); } // change patterns periodically
}