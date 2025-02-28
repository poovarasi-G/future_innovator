
#define motorpinLF1 14
#define motorpinLF2 16
#define motorpinLB2 33
#define motorpinLB1 32
#define motorpinRF1 19
#define motorpinRF2 17
#define motorpinRB1 25
#define motorpinRB2 26

// Encoder pin definitions
#define encoder_Pin_LF 27  // LF
#define encoder_Pin_LB 36  // LB
#define encoder_Pin_RF 34  // RF
#define encoder_Pin_RB 35  // RB

const int motorEnablePin = 13;

// Define PWM resolution and frequency
const int pwmResolution = 8;
const int pwmFrequency = 5000;

// Declare variables for motor speeds
int lf_speed = 203;
int lb_speed = 203;
int rf_speed = 210;
int rb_speed = 210;

// Variables to store the last time an interrupt was triggered
volatile unsigned long lastDebounceTimeLF = 0;
volatile unsigned long lastDebounceTimeLB = 0;
volatile unsigned long lastDebounceTimeRF = 0;
volatile unsigned long lastDebounceTimeRB = 0;
unsigned long debounceDelay = 100;  // 5 ms debounce time
// Encoder pulse counts
volatile unsigned int encoder_Pulse_Count_LF = 0;
volatile unsigned int encoder_Pulse_Count_LB = 0;
volatile unsigned int encoder_Pulse_Count_RF = 0;
volatile unsigned int encoder_Pulse_Count_RB = 0;


// ISR for counting encoder pulses with debouncing
void IRAM_ATTR countEncoderLF() {
  if (millis() - lastDebounceTimeLF > debounceDelay) {
    encoder_Pulse_Count_LF++;
    lastDebounceTimeLF = millis();
  }
}
void IRAM_ATTR countEncoderLB() {
  if (millis() - lastDebounceTimeLB > debounceDelay) {
    encoder_Pulse_Count_LB++;
    lastDebounceTimeLB = millis();
  }
}
void IRAM_ATTR countEncoderRF() {
  if (millis() - lastDebounceTimeRF > debounceDelay) {
    encoder_Pulse_Count_RF++;
    lastDebounceTimeRF = millis();
  }
}
void IRAM_ATTR countEncoderRB() {
  if (millis() - lastDebounceTimeRB > debounceDelay) {
    encoder_Pulse_Count_RB++;
    lastDebounceTimeRB = millis();
  }
}
void setup() {
  Serial.begin(9600);

  pinMode(motorEnablePin, OUTPUT);
  digitalWrite(motorEnablePin, HIGH);

  pinMode(motorpinLF1, OUTPUT);
  pinMode(motorpinLF2, OUTPUT);
  pinMode(motorpinLB1, OUTPUT);
  pinMode(motorpinLB2, OUTPUT);
  pinMode(motorpinRF1, OUTPUT);
  pinMode(motorpinRF2, OUTPUT);
  pinMode(motorpinRB1, OUTPUT);
  pinMode(motorpinRB2, OUTPUT);

  ledcSetup(0, pwmFrequency, pwmResolution);
  ledcSetup(1, pwmFrequency, pwmResolution);
  ledcSetup(2, pwmFrequency, pwmResolution);
  ledcSetup(3, pwmFrequency, pwmResolution);
  ledcSetup(4, pwmFrequency, pwmResolution);
  ledcSetup(5, pwmFrequency, pwmResolution);
  ledcSetup(6, pwmFrequency, pwmResolution);
  ledcSetup(7, pwmFrequency, pwmResolution);

  ledcAttachPin(motorpinLF1, 0);
  ledcAttachPin(motorpinLF2, 1);
  ledcAttachPin(motorpinLB1, 2);
  ledcAttachPin(motorpinLB2, 3);
  ledcAttachPin(motorpinRF1, 4);
  ledcAttachPin(motorpinRF2, 5);
  ledcAttachPin(motorpinRB1, 6);
  ledcAttachPin(motorpinRB2, 7);

  // Set encoder pins as inputs
  pinMode(encoder_Pin_LF, INPUT);
  pinMode(encoder_Pin_LB, INPUT);
  pinMode(encoder_Pin_RF, INPUT);
  pinMode(encoder_Pin_RB, INPUT);

  // Attach interrupts to encoder pins
  attachInterrupt(digitalPinToInterrupt(encoder_Pin_LF), countEncoderLF, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder_Pin_LB), countEncoderLB, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder_Pin_RF), countEncoderRF, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder_Pin_RB), countEncoderRB, CHANGE);
}

void loop() {
}

void Forward() {

  ledcWrite(0, lf_speed);
  ledcWrite(1, 0);
  ledcWrite(2, lb_speed);
  ledcWrite(3, 0);
  ledcWrite(4, rf_speed);
  ledcWrite(5, 0);
  ledcWrite(6, rb_speed);
  ledcWrite(7, 0);
 
}

void Backward() {

  ledcWrite(0, 0);
  ledcWrite(1, lf_speed);
  ledcWrite(2, 0);
  ledcWrite(3, lb_speed);
  ledcWrite(4, 0);
  ledcWrite(5, rf_speed);
  ledcWrite(6, 0);
  ledcWrite(7, rb_speed);
}

void Left() {

  ledcWrite(0, 0);
  ledcWrite(1, lf_speed);
  ledcWrite(2, 0);
  ledcWrite(3, lb_speed);
  ledcWrite(4, rf_speed);
  ledcWrite(5, 0);
  ledcWrite(6, rb_speed);
  ledcWrite(7, 0);
}

void Right() {

  ledcWrite(0, lf_speed);
  ledcWrite(1, 0);
  ledcWrite(2, lb_speed);
  ledcWrite(3, 0);
  ledcWrite(4, 0);
  ledcWrite(5, rf_speed);
  ledcWrite(6, 0);
  ledcWrite(7, rb_speed);
  
}

void Stop() {
  ledcWrite(0, 0);
  ledcWrite(1, 0);
  ledcWrite(2, 0);
  ledcWrite(3, 0);
  ledcWrite(4, 0);
  ledcWrite(5, 0);
  ledcWrite(6, 0);
  ledcWrite(7, 0);
 
}
