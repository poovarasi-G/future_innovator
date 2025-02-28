#include <FastLED.h>

#define LED_PIN     4      // Pin where the LED is connected
#define NUM_LEDS    1      // Only 1 LED
#define BRIGHTNESS  150     // Set brightness (0-255)
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  rainbowSingleLED();
}

void rainbowSingleLED() {
  static uint8_t hue = 0; // Hue value starts at 0

  leds[0] = CHSV(hue, 255, 255); // Set LED color using hue
  FastLED.show();  // Update the LED
  
  hue += 3;        // Increment hue for color transition (adjust for speed)
  delay(20);       // Small delay for smooth transition
}