#pragma once

//----------------------------------------------------------------

#include <WiFi.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Firebase_ESP_Client.h>

#include "data.h"

//----------------------------------------------------------------

bool firebase_connect();

void firebase_send_data(sensors_event_t acc, sensors_event_t gyr);