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

void setup_firebae()
{
    // Firebase.begin()
}