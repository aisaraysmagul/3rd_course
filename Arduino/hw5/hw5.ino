const int ledPin = 13;
const int TiltPinForWindow = 2;
const int TiltPinForAlarm = 0;
const int trigPin = 4;
const int echoPin = 3;
const int ldrPin = A0;
const int tempPin = A1; 
const int vibrPin = A2;
int signalCurrentValue = 0;
int tiltSensorPreviousValue = 0;
int tiltSensorCurrentValue = 0;
int shakeTime = 1000;
long lastTimeMoved = 0;
const int THRESHOLD = 1;
const int movementThreshold = 20;
int ldrVal1 = 0;
int ldrVal = 0;
long value = 0;
int cm = 0;

void setup(){
  Serial.begin(9600);
  pinMode (TiltPinForWindow, INPUT);
  digitalWrite (TiltPinForWindow, HIGH);
  pinMode (TiltPinForAlarm, INPUT);
  digitalWrite (TiltPinForAlarm, LOW);
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  ldrVal1 = analogRead(ldrPin);
}
void loop(){
  tiltSensorCurrentValue=digitalRead(TiltPinForWindow);
  signalCurrentValue=digitalRead(TiltPinForAlarm);
  int val = analogRead(vibrPin); 
  ldrVal = analogRead(ldrPin); 
  int value = analogRead(tempPin); 
  float millivolts = (value / 1024.0) * 5000;
  float celsius = millivolts / 10; 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  value = pulseIn(echoPin, HIGH, 50000);
  cm = value / 58; 
  if (signalCurrentValue != tiltSensorCurrentValue || tiltSensorPreviousValue != tiltSensorCurrentValue){
    lastTimeMoved = millis();
    tiltSensorPreviousValue = tiltSensorCurrentValue;
    signalCurrentValue = tiltSensorCurrentValue;
  }
  if (val >= THRESHOLD || abs(ldrVal - ldrVal1) > movementThreshold || millis() - lastTimeMoved < shakeTime ||  celsius >= 37 || (cm >= 5 && cm <= 30)){
    ldrVal1 = ldrVal;
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
  } else{ 
    digitalWrite(ledPin, LOW);
  }


 
  
}const int ledPin = 13;
const int TiltPinForWindow = 2;
const int TiltPinForAlarm = 0;
const int trigPin = 4;
const int echoPin = 3;
const int ldrPin = A0;
const int tempPin = A1; 
const int vibrPin = A2;
int signalCurrentValue = 0;
int tiltSensorPreviousValue = 0;
int tiltSensorCurrentValue = 0;
int shakeTime = 1000;
long lastTimeMoved = 0;
const int THRESHOLD = 1;
const int movementThreshold = 20;
int ldrVal1 = 0;
int ldrVal = 0;
long value = 0;
int cm = 0;

void setup(){
  Serial.begin(9600);
  pinMode (TiltPinForWindow, INPUT);
  digitalWrite (TiltPinForWindow, HIGH);
  pinMode (TiltPinForAlarm, INPUT);
  digitalWrite (TiltPinForAlarm, LOW);
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  ldrVal1 = analogRead(ldrPin);
}
void loop(){
  tiltSensorCurrentValue=digitalRead(TiltPinForWindow);
  signalCurrentValue=digitalRead(TiltPinForAlarm);
  int val = analogRead(vibrPin); 
  ldrVal = analogRead(ldrPin); 
  int value = analogRead(tempPin); 
  float millivolts = (value / 1024.0) * 5000;
  float celsius = millivolts / 10; 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  value = pulseIn(echoPin, HIGH, 50000);
  cm = value / 58; 
  if (signalCurrentValue != tiltSensorCurrentValue || tiltSensorPreviousValue != tiltSensorCurrentValue){
    lastTimeMoved = millis();
    tiltSensorPreviousValue = tiltSensorCurrentValue;
    signalCurrentValue = tiltSensorCurrentValue;
  }
  if (val >= THRESHOLD || abs(ldrVal - ldrVal1) > movementThreshold || millis() - lastTimeMoved < shakeTime ||  celsius >= 37 || (cm >= 5 && cm <= 30)){
    ldrVal1 = ldrVal;
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
  } else{ 
    digitalWrite(ledPin, LOW);
  }


 
  
}
