#define IR_SENSOR_PIN 4  // Change to the pin where your IR sensor is connected

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);  // Set the IR sensor pin as input
  Serial.begin(9600);           // Start the Serial Monitor
  Serial.println("IR Sensor Test: Reading values...");
}

void loop() {
  int sensorValue = digitalRead(IR_SENSOR_PIN);  // Read the IR sensor
  Serial.print("IR Sensor Output: ");
  Serial.println(sensorValue);  // Print the output: 0 or 1
  delay(100);  // Add a small delay for readability
}
