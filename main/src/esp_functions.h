#pragma once

#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

void esp_reset();

void esp_create_data_queue(QueueHandle_t *queue_acc, QueueHandle_t *queue_gyr);

sensors_event_t esp_get_queue_element(QueueHandle_t queue);