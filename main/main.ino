#include <arduino-timer.h>

#include "src/wifi_driver.h"
#include "src/firebase.h"
#include "src/mpu6050.h"
#include "src/esp_functions.h"

auto timer = timer_create_default();
static sensors_event_t accelerometer;
static sensors_event_t gyroscope;
// static kolejka tablica

bool check_timer_callback(void *)
{
    mpu_collect_data(&accelerometer, &gyroscope);
    return true;
}

void setup()
{
    Serial.begin(115200);
    mpu_initialize();
    // if (!wifi_connect() && !firebase_connect() && !mpu_initialize())
    // {
    //     // if (!firebase_connect() && !mpu_initialize())
    //     // {
    //     esp_reset();
    //     //     }
    //     // }
    //     // else
    //     // {
    //     //     esp_reset();
    // }
    timer.every(1, check_timer_callback);
}

void loop()
{
    timer.tick();

    // mpu_collect_data(&accelerometer, &gyroscope);
    // if (wifi_check_status() != WL_CONNECTED)
    // {
    //     Serial.println("[Communication] Connection with WiFi network lost.");
    //     wifi_connect();
    //     firebase_connect();
    // }

    // if (mpu_collect_data(&accelerometer, &gyroscope))
    //     firebase_send_data(&accelerometer, &gyroscope);
    // delay(10000);
}
