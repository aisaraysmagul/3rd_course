const byte numeral[10][8] = {
{1,1,1,1,1,1,0,0}, // 0
{0,1,1,0,0,0,0,0}, // 1
{1,1,0,1,1,0,1,0}, // 2
{1,1,1,1,0,0,1,0}, // 3
{0,1,1,0,0,1,1,0}, // 4
{1,0,1,1,0,1,1,0}, // 5
{1,0,1,1,1,1,1,0}, // 6
{1,1,1,0,0,0,0,0}, // 7
{1,1,1,1,1,1,1,0}, // 8
{1,1,1,1,0,1,1,0} // 9
}; //A,B,C,D,E,F,G,dp

int segmentPins[7] = {2,3,4,5,6,7,8};
int digitPins[4] = {12,11,10,9};

const int trigPin = A0;
const int echoPin = A1;

long value = 0;
int cm = 0;

void setup() {                
  // initialize the digital pins as outputs.
  for(int i = 0; i < 4; i++){
    pinMode(digitPins[i], OUTPUT);
  };
  for(int i = 0; i < 4; i++){
    pinMode(digitPins[i], OUTPUT);    
  }; 
  for(int i = 0; i < 8; i++){
    pinMode(segmentPins[i], OUTPUT);
  };
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
}

// the loop routine runs over and over again forever:
void loop(){
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
  delay(10);
  digitalWrite(trigPin, LOW);
  value = pulseIn(echoPin, HIGH, 50000);
  cm = value / 58; // pulse width is 58 microseconds per cm
  Serial.print(value); 
  Serial.print(" , "); 
  Serial.println(cm);
  if (cm <10){
    digitalWrite(digitPins[3], LOW);
    digitalWrite(digitPins[2], LOW);
    digitalWrite(digitPins[1], LOW);
    digitalWrite(digitPins[0], HIGH); 
    int num1 = cm%10;
    for (int i =0;i<8;i++){
      digitalWrite(segmentPins[i], !numeral[num1][i]); 
    }
  }
  else if (cm<100){
    digitalWrite(digitPins[3], LOW);
    digitalWrite(digitPins[2], LOW);
    digitalWrite(digitPins[1], LOW);
    digitalWrite(digitPins[0], HIGH);
    int num1 = cm%10;
    for (int i =0;i<8;i++){
      digitalWrite(segmentPins[i], !numeral[num1][i]); 
    }        
    delay(10); 
    digitalWrite(digitPins[3], LOW);
    digitalWrite(digitPins[2], LOW);
    digitalWrite(digitPins[1], HIGH);
    digitalWrite(digitPins[0], LOW);

    int num2 = (cm/ 10) % 10;
    for (int i =0;i<8;i++){
      digitalWrite(segmentPins[i], !numeral[num2][i]); 
    };
    }
}
