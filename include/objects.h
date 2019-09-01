using namespace std;

class Position 
{
    const byte pin;
    int state;
    unsigned long time_since_change;
    int lights[4];
    bool active;

    public:
        Position(byte pinAttach, int stateAttach, int lightsAttach[4]):
            pin(pinAttach),
            state(stateAttach),
            lights(lightsAttach)
        {

        }

    void setup()
    {
        pinMode(pin, INPUT_PULLUP)
    }
    void loop()
    {
        time_since_change = millis();
    }
};
