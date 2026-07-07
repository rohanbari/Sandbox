#include <Arduino.h>

#include "led.h"
#include "web_server.h"
#include "wifi.h"

/*
 * main.cpp
 *
 * Application entry point. The setup sequence initializes serial, the LED,
 * connects to WiFi, and starts the HTTP server. `loop()` simply polls the
 * server for incoming requests.
 */

void setup()
{
    Serial.begin(115200);

    led_init();
    connectWiFi();

    // Start the web server (mounts SPIFFS and begins listening).
    beginWebServer();
}

void loop()
{
    // Serve incoming HTTP requests. This is non-blocking when no client is
    // connected and keeps the code simple for example purposes.
    handleWebServerClient();
}