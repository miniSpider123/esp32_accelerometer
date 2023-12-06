#include "wifi_driver.h"
#include "print_string.h"
#include "tags.h"

//----------------------------------------------------------------

bool wifi_connect(void)
{
  WiFi.disconnect();
  WiFi.begin(ESP_WIFI_SSID, ESP_WIFI_PASS);
  int retry_count = 1;
  while (retry_count++)
  {
    Serial << TAG_COMM << "Connecting to WiFi...\n";
    delay(DELAY_TIME);
    if (WiFi.status() == WL_CONNECTED)
    {
      Serial << TAG_COMM << "Connected to the WiFi network. SSID: " << ESP_WIFI_SSID << "\n";
      return true;
    }
    else
    {
      Serial << TAG_COMM << "Connecting to the WiFi network failed. Error code: " << wl_status_to_string(WiFi.status()) << "\n";
      if (retry_count == ESP_MAXIMUM_RETRY)
      {
        Serial << TAG_COMM << "Too many tries. Check WiFi settings.\n";
        return false;
      }
    }
  }
}

wl_status_t wifi_check_status(void)
{
  return WiFi.status();
}

const char *wl_status_to_string(wl_status_t status)
{
  switch (status)
  {
  case WL_NO_SHIELD:
    return "WL_NO_SHIELD";
  case WL_IDLE_STATUS:
    return "WL_IDLE_STATUS";
  case WL_NO_SSID_AVAIL:
    return "WL_NO_SSID_AVAIL";
  case WL_SCAN_COMPLETED:
    return "WL_SCAN_COMPLETED";
  case WL_CONNECTED:
    return "WL_CONNECTED";
  case WL_CONNECT_FAILED:
    return "WL_CONNECT_FAILED";
  case WL_CONNECTION_LOST:
    return "WL_CONNECTION_LOST";
  case WL_DISCONNECTED:
    return "WL_DISCONNECTED";
  default:
    return "Unknown status.";
  }
}