int ledPins[] = {6, 10, 5}; 
const int ldrpin = A0;
int value = 0;

void setup(){
  Serial.begin(9600);
  pinMode(ledPins[0],OUTPUT);
  pinMode(ledPins[1],OUTPUT);
  pinMode(ledPins[2],OUTPUT);
}
void loop(){
  value = analogRead(ldrpin);
  value = value-250;
  if (value < 0){
    value = 0;
  }
  analogWrite(ledPins[1], int(value));
  analogWrite(ledPins[2], int(value));
  analogWrite(ledPins[0], int(value));
  Serial.println(value);
}
