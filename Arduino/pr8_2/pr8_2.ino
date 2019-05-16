float temp;
int tempPin = A0; //arduino pin used for temperature sensor
int tempMin = 25; // the temperature to start the buzzer
int tempMax = 70;
int fan = 3; // the pin where fan is connected
int fanSpeed = 0;

void setup() {
  pinMode(fan, OUTPUT);
  pinMode(tempPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  temp = analogRead(tempPin);
  temp = (temp *5.0*100.0)/1024.0;
  Serial.println(temp); 
  delay(1000);
  if(temp < tempMin) { 
    fanSpeed = 0;
    digitalWrite(fan, LOW);}
  if((temp >= tempMin) && (temp <= tempMax)) 
  {
    fanSpeed = map(temp, tempMin, tempMax, 32, 255); 
    analogWrite(fan, fanSpeed); }
  

}
