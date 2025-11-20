#include "wifi.h"

/*
 * wifi.cpp
 *
 * Minimal WiFi connection helper used by the example application. The
 * implementation blocks until a connection is established; for production
 * code consider adding a timeout or running the connection flow asynchronously.
 */

void wifi_connect()
{
    // Start the connection process using the configured credentials.
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    // Block until connected. This is simple and fine for small examples,
    // but may be undesirable in applications that need to remain responsive
    // during startup.
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to WiFi...");
    }

    Serial.println("Connected to WiFi!");
    Serial.println("IP Address: " + WiFi.localIP().toString());
}
