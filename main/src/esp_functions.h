#pragma once

//----------------------------------------------------------------

#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

//----------------------------------------------------------------

/** @brief Resets ESP32. */
void esp_reset(void);

/** @brief Creates queue of data.
 * @param queue_acc - Pointer to queue for accelerometer data
 * @param queue_gyr - Pointer to queue for gyroscope data
 */
void esp_create_data_queue(QueueHandle_t *queue_acc, QueueHandle_t *queue_gyr);

/** @brief Gets one element from queue.
 * @param queue - Queue of sensor data
 * @return queue_element - Element of queue
 */
sensors_event_t esp_get_queue_element(QueueHandle_t queue);