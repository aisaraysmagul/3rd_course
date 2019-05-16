int sensorPin = A0;  //sensor's pin
int S_state = 0;  //sensor's state
const int ledPin = 7; 
const int ledPin1 = 8; 
const int ledPin2 = 9; 
const int ledPin3 = 10; 
const int ledPin4 = 11;

void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  S_state = analogRead(sensorPin);
  S_state /= 32; 
  int i = 0;
  
  int a=S_state%2;       
  int b=S_state/2 %2;     
  int c=S_state/4 %2;    
  int d=S_state/8 %2;    
  int e=S_state/16 %2;    

  digitalWrite(ledPin4,e); 
  digitalWrite(ledPin3,d); 
  digitalWrite(ledPin2,c);   
  digitalWrite(ledPin1,b);    
  digitalWrite(ledPin,a); 
}
