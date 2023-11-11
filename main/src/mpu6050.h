#include <Wire.h>
// #include <MPU6050.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

#define MPU_MAXIMUM_RETRY 50

bool mpu_initialize();

bool mpu_collect_data(sensors_event_t *accelerometer, sensors_event_t *gyroscope);