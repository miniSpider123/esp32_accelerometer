#include "src/wifi_driver.h"
#include "src/firebase.h"

void setup()
{
    Serial.begin(115200);
    connect_to_wifi();
    connect_firebase();
}

void loop()
{
    if (check_network_status() != WL_CONNECTED)
    {
        Serial.println("Connection with WiFi network lost.");
        connect_to_wifi();
        connect_firebase();
    }

    send_data();
    delay(10000);
}
