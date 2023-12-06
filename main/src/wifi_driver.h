#pragma once

//----------------------------------------------------------------

#include <Arduino.h>
#include <WiFi.h>
#include "data.h"

//----------------------------------------------------------------

/** @brief Connects Wi-Fi.
 * @return True if connecting succeed
 */
bool wifi_connect(void);

/** @brief Changes WL status to string value.
 * @param status - WL status
 * @return String value of WL status
 */
extern const char *wl_status_to_string(wl_status_t status);

/** @brief Checks Wi-Fi connect status.
 * @return Wi-Fi connect status
 */
wl_status_t wifi_check_status(void);