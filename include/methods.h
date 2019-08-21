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
    return true;
  }
  else{
    return false;
  }
}
void position_update(int position)
{
  //update neopixels to "push in progress"
  //update local json
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