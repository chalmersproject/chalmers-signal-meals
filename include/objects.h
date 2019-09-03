class Position
{
    int switch_pin;
    bool current_state;
    unsigned long time_since_change;
    int lights_positions[4];
    const char* status_name;
    unsigned long prev;
    unsigned long now = millis();

    public:
    Position(const char name[], int pin, bool state, int* lights)
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
    
    bool is_active(){
      if(digitalRead(switch_pin)){
        //debounce button
        prev = now;
        if((now - prev) > 50)
        {
            return ((digitalRead(switch_pin) ? false : true));  
        }  
      }
    }
    void send_to_firebase(){

    }

    void loop()
    {
        now = millis();
    }
};