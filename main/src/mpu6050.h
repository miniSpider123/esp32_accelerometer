#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

//----------------------------------------------------------------

#define MPU_MAXIMUM_RETRY 50

//----------------------------------------------------------------

bool mpu_initialize();

bool mpu_collect_data(QueueHandle_t queue_acc, QueueHandle_t queue_gyr);