#pragma once

#include <WiFi.h>
// #include <FirebaseJson.h>
// #include <FirebaseESP32.h>
#include <Firebase_ESP_Client.h>

#define FIREBASE_HOST "https://esp-mgr-default-rtdb.europe-west1.firebasedatabase.app/"
#define API_KEY "AIzaSyA8f2RjQS7JENP9kYXL0X6aZmjvh1XMlsk"
#define USER_EMAIL "ankapajak4@gmail.com"
#define USER_PASSWORD "ESP123mgr"

void connect_firebase();
void send_data();