#include "esp_functions.h"
#include "print_string.h"
#include "tags.h"

//----------------------------------------------------------------

#define QUEUE_ELEM_NUM 2000
#define RESET_DELAY 5000

//----------------------------------------------------------------

void esp_reset()
{
    Serial << TAG_ESP << "Device will restart in " << RESET_DELAY / 1000 << " seconds.";
    delay(RESET_DELAY);
    ESP.restart();
}

void esp_create_data_queue(QueueHandle_t *queue_acc, QueueHandle_t *queue_gyr)
{
    *queue_acc = xQueueCreate(QUEUE_ELEM_NUM, sizeof(sensors_event_t));
    *queue_gyr = xQueueCreate(QUEUE_ELEM_NUM, sizeof(sensors_event_t));
    if (queue_acc == NULL && queue_gyr == NULL)
    {
        Serial << TAG_ESP << "Error during create the queues.";
        esp_reset();
    }
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