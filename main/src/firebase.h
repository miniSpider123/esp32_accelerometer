#pragma once

#include <WiFi.h>
// #include <FirebaseJson.h>
// #include <FirebaseESP32.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Firebase_ESP_Client.h>

#include "data.h"

void firebase_connect();
void firebase_send_data(sensors_event_t *accelerometer, sensors_event_t *gyroscope);