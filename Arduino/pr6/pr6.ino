const int ledpin = 13;
const int ledpin2 = 11;
const int ledpin3 = 9;
const int ldrpin = A5;
int value = 0;

void setup(){
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
  pinMode(ledpin2,OUTPUT);
  pinMode(ledpin3,OUTPUT);
  pinMode(A5, INPUT);
                                                                                                                                                                                                                                                        //
}
void loop(){
  value = analogRead(ldrpin);
  Serial.println(value);
  analogWrite(ledpin, 250-value);
  analogWrite(ledpin2, 250-value);
  analogWrite(ledpin3, 250-value);
  delay(100);
}
