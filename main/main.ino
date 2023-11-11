#include "src/wifi_driver.h"
#include "src/firebase.h"
#include "src/mpu6050.h"
#include "src/esp_functions.h"

static sensors_event_t accelerometer;
static sensors_event_t gyroscope;
// static kolejka tablica

void setup()
{
    Serial.begin(115200);
    if (wifi_connect())
    {
        firebase_connect();
        mpu_initialize();
        if (!mpu_initialize())
        {
            esp_reset();
        }
    }
}

void loop()
{
    if (wifi_check_status() != WL_CONNECTED)
    {
        Serial.println("[Communication] Connection with WiFi network lost.");
        wifi_connect();
        firebase_connect();
    }

    if (mpu_collect_data(&accelerometer, &gyroscope))
        firebase_send_data(&accelerometer, &gyroscope);
    delay(10000);
}
