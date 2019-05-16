const int ledPin1 =  7;
const int ledPin2 =  4;
const int ledPin3 =  8;
const int ledPin4 =  13;
const int buttonPin = 2;   
long previousMillis = 0;        // will store last time LED was updated
int buttonState = 0;            // Checks if button is pushed
int buttonPush = 0;             // Toggles between 0 to hold state

void setup() {
  Serial.begin(9600);
// set the digital pin as output:
   pinMode(ledPin1, OUTPUT);
   pinMode(ledPin2, OUTPUT); 
   pinMode(ledPin3, OUTPUT); 
   pinMode(ledPin4, OUTPUT);       
   pinMode(buttonPin, INPUT);
}
void loop()
{
   
   buttonState = digitalRead(buttonPin);
   if (buttonState == 1) {
    unsigned long currentMillis = millis();
      buttonPush = 1;
      if (buttonPush == 1){
        Serial.println(currentMillis-previousMillis);
         if(currentMillis - previousMillis < 1000) {   //if button is pressed less then 1s
            previousMillis = millis(); 
            digitalWrite(ledPin1, HIGH);
            delay(250);
            digitalWrite(ledPin1, LOW);
            digitalWrite(ledPin2, HIGH);
            delay(250);
            digitalWrite(ledPin2, LOW);
            digitalWrite(ledPin3, HIGH);
            delay(250);
            digitalWrite(ledPin3, LOW);
            digitalWrite(ledPin4, HIGH);
            delay(250);
            digitalWrite(ledPin4, LOW);
         }
         if(currentMillis - previousMillis > 1000 and currentMillis - previousMillis < 3000) {  //if button is pressed less then 3s but greater than 1s
            digitalWrite(ledPin1, HIGH);
            delay(125);
            digitalWrite(ledPin1, LOW);
            digitalWrite(ledPin2, HIGH);
            delay(125);
            digitalWrite(ledPin2, LOW);
            digitalWrite(ledPin3, HIGH);
            delay(125);
            digitalWrite(ledPin3, LOW);
            digitalWrite(ledPin4, HIGH);
            delay(125);
            digitalWrite(ledPin4, LOW);
         }
         if(currentMillis - previousMillis > 3000) { //if button is pressed greater then 3s
            digitalWrite(ledPin1, HIGH);
            delay(63);
            digitalWrite(ledPin1, LOW);
            digitalWrite(ledPin2, HIGH);
            delay(63);
            digitalWrite(ledPin2, LOW);
            digitalWrite(ledPin3, HIGH);
            delay(63);
            digitalWrite(ledPin3, LOW);
            digitalWrite(ledPin4, HIGH);
            delay(63);
            digitalWrite(ledPin4, LOW);
         }
         else {
            buttonPush = 0;     
         }
      }
      else {
         digitalWrite(ledPin1, LOW); 
         digitalWrite(ledPin2, LOW);
         digitalWrite(ledPin3, LOW);
         digitalWrite(ledPin4, LOW);
      }
      
   }
}
