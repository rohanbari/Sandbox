#include "web_server.h"
#include "led.h"

// The HTML page is embedded as a C string so we can serve it directly
// without relying on SPIFFS. This makes deployment simpler for small
// examples where the page is static and bundled with firmware.
static const char INDEX_HTML[] = R"rawliteral(<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8" />
    <title>NodeMCU LED</title>
    <style>
      body {
        font-family: sans-serif;
        text-align: center;
        margin-top: 50px;
      }
        button {
        height: 100px;
        width: 400px;
            font-size: 1.5em;
            padding: 10px 20px;
        }
    </style>
  </head>
  <body>
    <h1>NodeMCU LED Control</h1>
    <p>
      LED is
      <span id="state">%STATE%</span>
    </p>
    <button onclick="location.href='/toggle'">Toggle LED</button>

    <script>
      // optional: you could poll the state here, but the placeholder works fine for now
    </script>
  </body>
</html>)rawliteral";

WiFiServer server(80);

void web_server_begin()
{
    // Start listening for incoming HTTP connections on port 80.
    server.begin();
}

void web_server_handle_client()
{
    WiFiClient client = server.available();
    if (!client)
        return;

    Serial.println("Client connected");

    // Read the request line (e.g. "GET / HTTP/1.1")
    String requestLine = client.readStringUntil('\n');
    requestLine.trim(); // remove trailing \r and whitespace
    Serial.println(requestLine);

    // Consume and discard remaining request headers until an empty line.
    // This ensures the TCP receive buffer is drained before we write.
    while (client.connected()) {
        String header = client.readStringUntil('\n');
        if (header == "\r" || header.length() == 0)
            break;
    }

    // Toggle LED if /toggle is requested
    if (requestLine.indexOf("GET /toggle") >= 0) {
        led_toggle();
    }

    // Serve the embedded index page, replacing the %STATE% placeholder.
    if (requestLine.indexOf("GET /") >= 0 || requestLine.indexOf("GET /index.html") >= 0) {
        String page = INDEX_HTML; // copy into mutable String
        page.replace("%STATE%", led_is_on() ? "ON" : "OFF");

        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println("Connection: close");
        client.println();

        client.print(page);

        // Give TCP stack a short time to flush outgoing data before closing
        // the connection. On some clients closing immediately can appear as
        // a connection reset. 5 ms is sufficient for small pages.
        delay(5);
    } else {
        // Anything else → 404
        client.println("HTTP/1.1 404 Not Found");
        client.println();
        delay(2);
    }

    client.stop();
    Serial.println("Client disconnected");
}
