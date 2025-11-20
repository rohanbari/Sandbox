#ifndef WIFI_H
#define WIFI_H

#include <ESP8266WiFi.h>

/*
 * wifi.h
 *
 * WiFi credentials and a small helper to connect to the configured AP.
 *
 * WARNING: Hardcoding credentials in source is convenient for examples but
 * insecure for real projects. Consider keeping secrets out of version
 * control or using build-time flags / a separate (ignored) config file.
 */

// Default credentials used by the example. Replace with your network values
// or override them at build time.
// `inline` gives these variables external linkage with a single definition
// across translation units (C++17). This avoids multiple-definition errors
// when the header is included from several .cpp files.
inline const char* WIFI_SSID = "Photoelectron";
inline const char* WIFI_PASSWORD = "linuxman123";

// Connect to WiFi; blocks until a connection is established.
void wifi_connect();

#endif