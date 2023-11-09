#include "firebase.h"
#include "print_string.h"
#include "tags.h"

FirebaseData firebase_data;
FirebaseAuth firebase_auth;
FirebaseConfig firebase_config;
FirebaseJson acc_X;
FirebaseJson acc_Y;
FirebaseJson acc_Z;

void connect_firebase()
{
    String uid;
    String path;
    firebase_config.host = FIREBASE_HOST;
    firebase_config.api_key = API_KEY;

    firebase_auth.user.email = USER_EMAIL;
    firebase_auth.user.password = USER_PASSWORD;

    Serial << FIREBASE_TAG << "Connecting to database...\n";
    while (1)
    {
        Firebase.begin(&firebase_config, &firebase_auth);
        Firebase.reconnectWiFi(true);

        Serial << FIREBASE_TAG << "Getting User UID\n";
        while (firebase_auth.token.uid == "")
        {
            Serial.print('.');
            delay(1000);
        }

        uid = firebase_auth.token.uid.c_str();
        Serial << FIREBASE_TAG << "User UID: " << uid << "\n";
        path = "esp/" + uid;

        if (!Firebase.RTDB.beginStream(&firebase_data, path.c_str()))
            Serial << FIREBASE_TAG << "Error during stream connecting: " << firebase_data.errorReason().c_str() << ".\n";
        else
        {
            Serial << FIREBASE_TAG << "Successful connecting to stream.\n";
            break;
        }
    }
}

void send_data()
{
    acc_X.set("/acc/ox", random(1, 8));
    acc_Y.set("/acc/oy", random(1, 8));
    acc_Z.set("/acc/oz", random(1, 8));
    Serial << FIREBASE_TAG << "Sending data to firebase.\n";
    // Firebase.update(firebase_data, "/acc/ox", acc_X);
    // Firebase.update(firebase_data, "/acc/oy", acc_Y);
    // Firebase.update(firebase_data, "/acc/oz", acc_Z);
}