const int ledPin = 2; // choose the pin for the LED
const int inputPin = 7; // choose the input pin (for a pushbutton)

int state = 0; 
void setup() {
  pinMode(ledPin, OUTPUT); // declare LED as output
  pinMode(inputPin, INPUT); // declare pushbutton as input
  
}

void loop() {
  state = digitalRead(inputPin);
  if (state == HIGH){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
}
