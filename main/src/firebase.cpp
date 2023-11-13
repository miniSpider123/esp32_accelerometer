#include "firebase.h"
#include "print_string.h"
#include "tags.h"
#include "data.h"

FirebaseData firebase_data;
FirebaseAuth firebase_auth;
FirebaseConfig firebase_config;
FirebaseJson acc_X;
FirebaseJson acc_Y;
FirebaseJson acc_Z;

bool firebase_connect()
{
    String uid;
    String path;
    firebase_config.host = FIREBASE_HOST;
    firebase_config.api_key = API_KEY;

    firebase_auth.user.email = USER_EMAIL;
    firebase_auth.user.password = USER_PASSWORD;

    Serial << TAG_FIREBASE << "Connecting to database...\n";
    int retry_count = FIREBASE_MAXIMUM_RETRY;
    while (retry_count--)
    {
        Firebase.begin(&firebase_config, &firebase_auth);
        Firebase.reconnectWiFi(true);

        Serial << TAG_FIREBASE << "Getting User UID\n";
        while (firebase_auth.token.uid == "")
        {
            Serial.print('.');
            delay(1000);
        }

        uid = firebase_auth.token.uid.c_str();
        Serial << TAG_FIREBASE << "User UID: " << uid << "\n";
        path = "esp/" + uid;

        if (!Firebase.RTDB.beginStream(&firebase_data, path.c_str()))
            Serial << TAG_FIREBASE << "Error during stream connecting: " << firebase_data.errorReason().c_str() << ".\n";
        else
        {
            Serial << TAG_FIREBASE << "Successful connecting to stream.\n";
            return true;
        }
    }
    return false;
}

void firebase_send_data(sensors_event_t *accelerometer, sensors_event_t *gyroscope)
{
    Serial << TAG_FIREBASE << "Sending data to firebase.\n";
    // dwie niezależne fkcje (wysylanie i zbieranie danych); sa niezalezne, wiec
    // mozna zbierac dane co minute, a wysylac co 5 s; to co zbiera dane wrzuca to do kolejki,
    // a to co wysyla jak zobaczy, ze jest jedna dana to probuje wyslac; dla >10 danych (brak wifi)
    // droppuje te dane (bufor w ramie)
    // dodatkowo: lapanie ok. 10000 danych i wysylac takie duze paczki (np)
    if (!Firebase.RTDB.pushFloat(&firebase_data, "/acc/ox", accelerometer->acceleration.x) ||
        !Firebase.RTDB.pushFloat(&firebase_data, "/acc/oy", accelerometer->acceleration.y) ||
        !Firebase.RTDB.pushFloat(&firebase_data, "/acc/oz", accelerometer->acceleration.z))
        Serial << TAG_FIREBASE << "Sample dropped.\n";
}