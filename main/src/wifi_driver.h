#pragma once

//----------------------------------------------------------------

#include <Arduino.h>
#include <WiFi.h>
#include "data.h"

//----------------------------------------------------------------

bool wifi_connect();

extern const char *wl_status_to_string(wl_status_t status);

wl_status_t wifi_check_status();