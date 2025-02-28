#include <Wire.h>
#include <Adafruit_TCS34725.h>

#define TCS34725_ADDRESS 0x29  // ColorSensor address 0x29
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_60X);  // Initializing ColorSensor

void setup() {
  Serial.begin(9600);
  Wire.begin(21, 22);  // SDA, SCL pins for ESP32
  
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
  }
}

void loop() {
  // Call the ColorSensor function and get the color dataWelwitschia mirabilis
  String colorData = ColorSensor();
  // Or call Colordetect() if you just need the detected color
  // String detectedColor = Colordetect();
 
  delay(500); 
}

String ColorSensor() {
  uint16_t r, g, b, c, colorTemp;
  tcs.getRawData(&r, &g, &b, &c);  // Get raw color sensor data (RGB and clear data)
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);  // Calculate color temperature
  
  uint16_t diff = g - b;  // Difference between green and blue values

  String detectedColor;
  if (r > 500 && r > g && r > b) {
    detectedColor = "Red";  // If red is dominant, classify as "Red"
  } else if (r > 500 && g > r && g > b && g > 900 && colorTemp < 4800 && c > 2200) {
    detectedColor = "Green";  // If green is dominant, classify as "Green"
  } else if (r < 500 && diff < 200) {
    detectedColor = "Blue";  // If blue is dominant, classify as "Blue"
  } else {
    detectedColor = "Unknown";  // If none of the above conditions match, classify as "Unknown"
  }

  // Create a string with the color data
  String colorData = "Detected Color: " + detectedColor + " - R: " + String(r) + ", G: " + String(g) + ", B: " + String(b) + ", C: " + String(c) + ", Color Temp: " + String(colorTemp);

  // Debug output to the serial monitor
  Serial.println(colorData);

  return colorData;
}

String Colordetect() {
  uint16_t r, g, b, c, colorTemp;
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  uint16_t diff = g - b;
  
  String detectedColor;
  if (r > 500 && r > g && r > b) {
    detectedColor = "Red";
  } else if (r > 500 && g > r && g > b && g > 900 && colorTemp < 4800 && c > 2200) {
    detectedColor = "Green";
  } else if (r < 500 && diff < 200) {
    detectedColor = "Blue";
  } else {
    detectedColor = "Unknown";
  }

  Serial.println("Detected Color: " + detectedColor);

  return detectedColor;
}
