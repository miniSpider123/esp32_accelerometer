#pragma once

//----------------------------------------------------------------

#include <WiFi.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Firebase_ESP_Client.h>

#include "data.h"

//----------------------------------------------------------------

/** @brief Connects and logs to firebase.
 * @return True if connected and logged to firebase.
 */
bool firebase_connect(void);

/** @brief Sends data to realtime database.
 * @param acc - data struct from accelerometer
 * @param gyr - data struct from gyroscope
 */
void firebase_send_data(sensors_event_t acc, sensors_event_t gyr);