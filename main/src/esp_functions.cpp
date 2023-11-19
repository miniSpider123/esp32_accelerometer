#include "esp_functions.h"
#include "print_string.h"
#include "tags.h"

void esp_reset()
{
    Serial << TAG_ESP << "Device will restart in 10 seconds.";
    delay(10000);
    ESP.restart();
}

void esp_create_data_queue(QueueHandle_t *queue_acc, QueueHandle_t *queue_gyr)
{
    size_t queue_elem_num = 2000;
    *queue_acc = xQueueCreate(queue_elem_num, sizeof(sensors_event_t));
    *queue_gyr = xQueueCreate(queue_elem_num, sizeof(sensors_event_t));
    if (queue_acc == NULL && queue_gyr == NULL)
    {
        Serial.println("Error creating the queue.");
        Serial.println((int)queue_acc);
        Serial.println((int)queue_gyr);
        Serial.println(sizeof(sensors_event_t));
        esp_reset();
    }
    Serial.print("Initialized Queues. Size of element: ");
    Serial.println(sizeof(sensors_event_t));
}

sensors_event_t esp_get_queue_element(QueueHandle_t queue)
{
    sensors_event_t queue_element;
    if (queue != NULL)
    {
        xQueueReceive(queue, &queue_element, portMAX_DELAY);
    }
    return queue_element;
}