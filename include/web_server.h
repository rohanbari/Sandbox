/*
 * web_server.h
 *
 * Simple HTTP server helpers. The implementation serves `index.html` from
 * SPIFFS and exposes a tiny control endpoint (`/toggle`) to toggle a local
 * LED via `led_toggle()`.
 */

#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <Arduino.h>
#include <ESP8266WiFi.h>

// Start listening for HTTP clients and mount SPIFFS. Returns immediately.
void beginWebServer();

// Poll and handle a single client if one is available. Call frequently from
// the main `loop()` to keep the server responsive.
void handleWebServerClient();

#endif // WEB_SERVER_H
