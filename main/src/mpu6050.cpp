#include "mpu6050.h"
#include "print_string.h"
#include "tags.h"

Adafruit_MPU6050 mpu;
sensors_event_t acc, gyr;

bool mpu_initialize()
{
    // bool val = mpu.begin();
    // if (val)
    //     return true;
    // else
    //     return false;
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
    if (accelerometer != null && gyroscope != null)
        // sprawdzić czy accelerometer i gyroscope jest nullem
        return mpu.getEvent(&accelerometer, &gyroscope, null);
    Serial << TAG_MPU;
    return false;
}