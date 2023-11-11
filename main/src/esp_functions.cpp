#include "esp_functions.h"
#include "print_string.h"
#include "tags.h"

void esp_reset()
{
    Serial << TAG_ESP << "Device will restart in 10 seconds.";
    delay(10000);
    ESP.restart();
}