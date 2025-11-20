#ifndef LED_H
#define LED_H

#include <Arduino.h>

/*
 * led.h
 *
 * Lightweight LED helper API for this project.
 *
 * This header exposes a small, hardware-agnostic LED API and documents the
 * board's LED polarity so application code can use meaningful names
 * (`LED_ON` / `LED_OFF`) instead of remembering `HIGH` vs `LOW` semantics.
 *
 * Configure `LED_ACTIVE_LOW` to `false` if your board drives the LED with
 * an active-HIGH signal.
 */

// Pin and polarity configuration
static constexpr uint8_t LED_PIN = LED_BUILTIN;
// Set to true if the LED is active LOW (common on NodeMCU/ESP boards)
static constexpr bool LED_ACTIVE_LOW = true;

// Derived ON/OFF values so code doesn't need to remember HIGH/LOW semantics
static constexpr uint8_t LED_ON = LED_ACTIVE_LOW ? LOW : HIGH;
static constexpr uint8_t LED_OFF = LED_ACTIVE_LOW ? HIGH : LOW;

// Initialize the LED pin and set it to the defined OFF state.
void led_init();

// Toggle the LED state (ON -> OFF, OFF -> ON).
void led_toggle();

// Return true when the LED is currently lit (honors LED_ACTIVE_LOW).
bool led_is_on();

#endif