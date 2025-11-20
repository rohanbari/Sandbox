# Sandbox (NodeMCU LED Web Control)

Small example project demonstrating a minimal HTTP server on an ESP8266/NodeMCU
that serves a static `index.html` from SPIFFS and exposes a `/toggle` endpoint
to control the board's built-in LED.

Files of interest
- `src/main.cpp` — application entry point (initializes serial, WiFi, LED,
  and starts the HTTP server).
- `lib/led.h` / `lib/led.cpp` — small LED abstraction with explicit polarity
  configuration (`LED_ACTIVE_LOW`) and `LED_ON`/`LED_OFF` constants.
- `lib/wifi.cpp` / `include/wifi.h` — WiFi connect helper and credentials.
- `lib/web_server.h` / `lib/web_server.cpp` — tiny HTTP server that serves
  `/index.html` from SPIFFS and handles `/toggle` to flip the LED.
- `lib/index.html` — static web UI that shows the LED state and has a toggle
  button.

Build & upload

1. Build the project:

```powershell
platformio run
```

2. Build and upload (example environment `nodemcuv2` — replace with your env):

```powershell
platformio run --target upload --environment nodemcuv2
```

Notes and recommendations
- The WiFi credentials in `include/wifi.h` are hardcoded for convenience. Do
  not commit real secrets to version control; instead use build flags,
  environment variables, or a local ignored config file for production.
- The example mounts SPIFFS at startup. Ensure `lib/index.html` is packaged
  into the firmware image (PlatformIO's `data`/`data` folder or project
  configuration may be required depending on your setup).
- The `wifi_connect()` function currently blocks until connected. Add a
  timeout or make it non-blocking if the application needs to remain
  responsive during WiFi setup.

If you want, I can:
- Add `led_on()` / `led_off()` helpers.
- Add a small demo in `src/main.cpp` that blinks the LED while connecting.
- Move WiFi credentials to a separate, ignored config file and update build
  instructions.
