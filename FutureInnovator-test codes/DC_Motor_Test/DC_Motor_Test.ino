
// Define motor pins
#define motorpinLF1 14
#define motorpinLF2 16
#define motorpinLB1 32
#define motorpinLB2 33
#define motorpinRF1 19
#define motorpinRF2 17
#define motorpinRB1 25
#define motorpinRB2 26
const int motorEnablePin = 13;  // Motor enable
int speed = 200;
int frequency = 5000;
int resolution = 8;

void setup() {
  Serial.begin(9600);
  pinMode(motorEnablePin, OUTPUT);
  digitalWrite(motorEnablePin, HIGH);

  ledcSetup(0, frequency, resolution);
  ledcSetup(1, frequency, resolution);
  ledcSetup(2, frequency, resolution);
  ledcSetup(3, frequency, resolution);
  ledcSetup(4, frequency, resolution);
  ledcSetup(5, frequency, resolution);
  ledcSetup(6, frequency, resolution);
  ledcSetup(7, frequency, resolution);

  ledcAttachPin(motorpinLF1, 0);
  ledcAttachPin(motorpinLF2, 1);
  ledcAttachPin(motorpinLB1, 2);
  ledcAttachPin(motorpinLB2, 3);
  ledcAttachPin(motorpinRF1, 4);
  ledcAttachPin(motorpinRF2, 5);
  ledcAttachPin(motorpinRB1, 6);
  ledcAttachPin(motorpinRB2, 7);

  ledcWrite(0, 255);
  ledcWrite(1, 255);
  ledcWrite(2, 255);
  ledcWrite(3, 255);
  ledcWrite(4, 255);
  ledcWrite(5, 255);
  ledcWrite(6, 255);
  ledcWrite(7, 255);
}

void loop() {

  motorTest();
}

void motorTest() {
  // Test the motors by running them in different directions
  forward();
  // delay(5000);
  // stopMotor();
  // delay(5000);
  // backward();
  // delay(5000);
  // stopMotor();
  // delay(5000);
  // left();
  // delay(5000);
  // stopMotor();
  // delay(5000);
  // right();
  // delay(5000);
  // stopMotor();
  // delay(5000);
}

void forward() {
  ledcWrite(0, speed);
  ledcWrite(1, 0);
  ledcWrite(2, speed);
  ledcWrite(3, 0);
  ledcWrite(4, speed);
  ledcWrite(5, 0);
  ledcWrite(6, speed);
  ledcWrite(7, 0);
}

void backward() {
  ledcWrite(0, 0);
  ledcWrite(1, speed);
  ledcWrite(2, 0);
  ledcWrite(3, speed);
  ledcWrite(4, 0);
  ledcWrite(5, speed);
  ledcWrite(6, 0);
  ledcWrite(7, speed);
}

void right() {
  ledcWrite(0, speed);
  ledcWrite(1, 0);
  ledcWrite(2, speed);
  ledcWrite(3, 0);
  ledcWrite(4, 0);
  ledcWrite(5, speed);
  ledcWrite(6, 0);
  ledcWrite(7, speed);
}

void left() {
  ledcWrite(0, 0);
  ledcWrite(1, speed);
  ledcWrite(2, 0);
  ledcWrite(3, speed);
  ledcWrite(4, speed);
  ledcWrite(5, 0);
  ledcWrite(6, speed);
  ledcWrite(7, 0);
}

void stopMotor() {
  ledcWrite(0, 0);
  ledcWrite(1, 0);
  ledcWrite(2, 0);
  ledcWrite(3, 0);
  ledcWrite(4, 0);
  ledcWrite(5, 0);
  ledcWrite(6, 0);
  ledcWrite(7, 0);
}
