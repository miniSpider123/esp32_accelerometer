#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

//----------------------------------------------------------------

#define MPU_MAXIMUM_RETRY 50

//----------------------------------------------------------------

/** @brief Initializates MPU-6050 sensor.
 * @return True if initialization succeed
 */
bool mpu_initialize(void);

/** @brief Collects data from MPU-6050 sensor and add to queues.
 * @param queue_acc - Queue of accelerometer data
 * @param queue_gyr - Queue of gyroscope data
 * @return True if collecting succeed
 */
bool mpu_collect_data(QueueHandle_t queue_acc, QueueHandle_t queue_gyr);