#pragma once

#include <Arduino.h>
#include <WiFi.h>

#define ESP_WIFI_SSID "wunsz_rzeczny"
#define ESP_WIFI_PASS "9eed0d14371c"
#define ESP_MAXIMUM_RETRY 10
#define DELAY_TIME 10000

bool wifi_connect();

extern const char *wl_status_to_string(wl_status_t status);

wl_status_t wifi_check_status();