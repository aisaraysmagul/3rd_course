int sensorPin = A0;
int sensorVal = 0;
int numPins = 6;

int ledPins[] = {6,7, 8, 9, 10, 11};   // an array of pin numbers to which LEDs are attached
int ledStates[] = {LOW, LOW, LOW, LOW, LOW, LOW};


void setup() {
  Serial.begin(9600);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
}
void blinked(){
  digitalWrite(ledPins[5], HIGH);
  delay(400);
  digitalWrite(ledPins[5], LOW);
  delay(400); 
}
void loop() {
  sensorVal = analogRead(sensorPin);
  sensorVal /= 170; 
  for(int i = 0; i < numPins; i++) {
    if(sensorVal <= i) {
      ledStates[i] = HIGH;
    }
    else {
      ledStates[i] = LOW;
    }
    if(sensorVal < 0.3){
      blinked();
    }
    digitalWrite(ledPins[i], ledStates[i]);
  }
}
