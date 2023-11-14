#include "mpu6050.h"
#include "print_string.h"
#include "tags.h"

#include <stdio.h>
#include <sys/time.h>

Adafruit_MPU6050 mpu;
static sensors_event_t temp;

bool mpu_initialize()
{
    int retry_count = MPU_MAXIMUM_RETRY;
    while (retry_count--)
    {
        if (mpu.begin())
        {
            Serial << TAG_MPU << "MPU6050 connection successfully.\n";
            mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
            mpu.setGyroRange(MPU6050_RANGE_500_DEG);
            mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
            return true;
        }
        delay(1000);
    }
    Serial << TAG_MPU << "MPU6050 not found.\n";
    return false;
}

bool mpu_collect_data(sensors_event_t *accelerometer, sensors_event_t *gyroscope)
{
    if (accelerometer != NULL && gyroscope != NULL)
    {
        Serial.print(accelerometer->acceleration.x);
        Serial.print(",");
        Serial.print(accelerometer->acceleration.y);
        Serial.print(",");
        Serial.print(accelerometer->acceleration.z);
        Serial.print(",");
        Serial.print(gyroscope->gyro.x);
        Serial.print(",");
        Serial.print(gyroscope->gyro.y);
        Serial.print(",");
        Serial.println(gyroscope->gyro.z);
        return mpu.getEvent(accelerometer, gyroscope, &temp);
    }
    Serial << TAG_MPU << "Invalid data queue parameter.\n";
    return false;
}