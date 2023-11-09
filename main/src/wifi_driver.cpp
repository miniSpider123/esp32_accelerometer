#include "wifi_driver.h"
#include "print_string.h"
#include "tags.h"

void connect_to_wifi()
{
  // WiFi.disconnect();
  WiFi.begin(ESP_WIFI_SSID, ESP_WIFI_PASS);
  int retry_count = 1;
  while (retry_count++)
  {
    Serial << COMM_TAG << "Connecting to WiFi...\n";
    delay(DELAY_TIME);
    if (WiFi.status() == WL_CONNECTED)
    {
      Serial << COMM_TAG << "Connected to the WiFi network. SSID: " << ESP_WIFI_SSID << "\n";
      break;
    }
    else
    {
      Serial << COMM_TAG << "Connecting to the WiFi network failed. Error code: " << wl_status_to_string(WiFi.status()) << "\n";
      if (retry_count == ESP_MAXIMUM_RETRY)
      {
        Serial << COMM_TAG << "Too many tries. Check WiFi settings.\n";
        break;
      }
    }
  }
}

wl_status_t check_network_status()
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