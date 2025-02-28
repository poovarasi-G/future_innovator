#define touchSensorPin 12  // Define the touch sensor pin

void setup() {
  Serial.begin(9600);  
  pinMode(touchSensorPin, INPUT);  
}

void loop() {
  touch(); 
}

void touch() {
  int touchValue = touchRead(touchSensorPin);  
  
  // Print the touch sensor value for debugging
  Serial.print("Touch sensor value: ");
  Serial.println(touchValue);
  
  if (touchValue > 0) {  // If the touch sensor is activated (touched)
    Serial.println("Touch detected!"); 
  } else {  
    Serial.println("No touch detected.");  
  }
}
