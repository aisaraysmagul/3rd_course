const int ledPin = 2;
const int ledPin1 = 4; 
const int ledPin2 = 13; 
const int ledPin3 = 10; 
const int inputPin = 7; 
const int iPin2 = 12;
int aa[] = {ledPin, ledPin1, ledPin2, ledPin3};
void setup() {
  pinMode(ledPin, OUTPUT); // declare LED as output
  pinMode(ledPin1, OUTPUT); // declare LED as output
  pinMode(ledPin2, OUTPUT); // declare LED as output
  pinMode(ledPin3, OUTPUT); // declare LED as output
  pinMode(inputPin, INPUT); // declare pushbutton as input
  pinMode(iPin2, INPUT); 
}
void loop(){
  int val = digitalRead(inputPin); 
  int val2 = digitalRead(iPin2);
  if(val == HIGH){
    for(int i=0;i<9;i++){  
     int a=i%2;       
     int b=i/2 %2;     
     int c=i/4 %2; 
     int d=i/8 %2;     
     digitalWrite(ledPin3,d); 
     digitalWrite(ledPin2,c);   
     digitalWrite(ledPin1,b);   
     digitalWrite(ledPin,a);  
     delay(500);
     } 
    val = digitalRead(inputPin);
  }
  if(val2 == HIGH){
    for(int i=9;i<16;i++){  
     int a=i%2;       
     int b=i/2 %2;     
     int c=i/4 %2; 
     int d=i/8 %2;     
     digitalWrite(ledPin3,d); 
     digitalWrite(ledPin2,c);   
     digitalWrite(ledPin1,b);   
     digitalWrite(ledPin,a);  
     delay(500);
     } 
    val2 = digitalRead(iPin2);
  }
}
