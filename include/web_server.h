/*
 * web_server.h
 *
 * Simple HTTP server helpers. The implementation serves `index.html` from
 * SPIFFS and exposes a tiny control endpoint (`/toggle`) to toggle a local
 * LED via `led_toggle()`.
 *
 * The header provides two functions:
 *  - `web_server_begin()` to start the server
 *  - `web_server_handle_client()` to be called frequently from `loop()` to
 *     process incoming requests
 */

#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <Arduino.h>
#include <ESP8266WiFi.h>

// Start listening for HTTP clients and mount SPIFFS. Returns immediately.
void web_server_begin();

// Poll and handle a single client if one is available. Call frequently from
// the main `loop()` to keep the server responsive.
void web_server_handle_client();

#endif // WEB_SERVER_H
