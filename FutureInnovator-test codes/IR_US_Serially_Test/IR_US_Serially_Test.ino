#include <NewPing.h>

const int LeftSensorPin = 2;  // Front IR sensor pins
const int RightSensorPin = 23;
const int TRIGGER_PIN = 5;
const int ECHO_PIN = 18;
const int MAX_DISTANCE = 200;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  pinMode(LeftSensorPin, INPUT);
  pinMode(RightSensorPin, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  int LeftSensorValue = digitalRead(LeftSensorPin);
  int RightSensorValue = digitalRead(RightSensorPin);
  unsigned int distance = sonar.ping_cm();

  Serial.print("Distance: ");
  Serial.println(distance);

  Serial.print("LeftirSensor: ");
  Serial.println(LeftSensorValue);

  Serial.print("RightirSensor: ");
  Serial.println(RightSensorValue);

  delay(500);  // Optional delay between readings
}
