#include <ESP32Servo.h>
#define SERVO_PIN 18
Servo servo;           
void setup() {
  Serial.begin(9600);
  servo.attach(SERVO_PIN);
}
void moveServoTo(int angle) {
  angle = constrain(angle, 0, 180); // Constrain the angle between 70 and 130 degrees//constrain(angle, 70, 130)
  servo.write(angle);               // Move the servo to the specified angle
   delay(10);     
}
void loop() {
  moveServoTo(100);   // Servo Right turn.
  delay(1000);          // Delay for 1 second.
  moveServoTo(180);  // Servo Center turn.
  delay(1000);  
}