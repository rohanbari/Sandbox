#include "led.h"

void led_init()
{
    pinMode(LED_PIN, OUTPUT);
    // Write the defined OFF level so the initial state is explicit and portable.
    digitalWrite(LED_PIN, LED_OFF);
}

void led_toggle()
{
    // Toggle the LED state explicitly using LED_ON/LED_OFF so polarity is clear.
    const uint8_t current = digitalRead(LED_PIN);
    digitalWrite(LED_PIN, (current == LED_ON) ? LED_OFF : LED_ON);
}

bool led_is_on()
{
    // Return whether the LED is currently on, honoring LED_ACTIVE_LOW.
    return digitalRead(LED_PIN) == LED_ON;
}
