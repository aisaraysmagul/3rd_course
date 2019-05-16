int stepperPins[4] = {8,9,10,11};

char ch,ch1,ch2,ch3;
int delayTime = 3;
int count;
int dec;
String prii;
int digits[3];
void setup() {
  Serial.begin(9600);
  for(int i=0; i<4; i++){
    pinMode(stepperPins[i], OUTPUT);}
}
void loop(){
  delay(1000);
  if(Serial.available()){
    count = 0;
    while (Serial.available()) {
        ch = Serial.read();
        if(isdigit(ch)){
          digits[count] = ch-'0';
          count++;
          }
      }    
   }
  if (count==1){dec = digits[0];}
  else if (count ==2){dec = (digits[0] * 10 + ( digits[1]));}
  else if (count==3){dec = (digits[0]*100 + digits[1] * 10 + digits[2]);}

  Serial.print(ch);
  Serial.println(dec);
  if(ch == 'B'){
  for(int i=0; i<dec; i++){
   digitalWrite(stepperPins[3], HIGH);
   digitalWrite(stepperPins[2], LOW);
   digitalWrite(stepperPins[1], LOW);
   digitalWrite(stepperPins[0], LOW);
   delay(delayTime);
   digitalWrite(stepperPins[3], LOW);
   digitalWrite(stepperPins[2], HIGH);
   digitalWrite(stepperPins[1], LOW);
   digitalWrite(stepperPins[0], LOW);
   delay(delayTime);
   digitalWrite(stepperPins[3], LOW);
   digitalWrite(stepperPins[2], LOW);
   digitalWrite(stepperPins[1], HIGH);
   digitalWrite(stepperPins[0], LOW);
   delay(delayTime);
   digitalWrite(stepperPins[3], LOW);
   digitalWrite(stepperPins[2], LOW);
   digitalWrite(stepperPins[1], LOW);
   digitalWrite(stepperPins[0], HIGH);
   delay(delayTime);
   }
  ch=='x';dec = 0;
  }
   else if(ch == 'F'){
    for(int j=0; j<dec; j++){
     digitalWrite(stepperPins[0], HIGH);
     digitalWrite(stepperPins[1], LOW);
     digitalWrite(stepperPins[2], LOW);
     digitalWrite(stepperPins[3], LOW);
     delay(delayTime);
     digitalWrite(stepperPins[0], LOW);
     digitalWrite(stepperPins[1], HIGH);
     digitalWrite(stepperPins[2], LOW);
     digitalWrite(stepperPins[3], LOW);
     delay(delayTime);
     digitalWrite(stepperPins[0], LOW);
     digitalWrite(stepperPins[1], LOW);
     digitalWrite(stepperPins[2], HIGH);
     digitalWrite(stepperPins[3], LOW);
     delay(delayTime);
     digitalWrite(stepperPins[0], LOW);
     digitalWrite(stepperPins[1], LOW);
     digitalWrite(stepperPins[2], LOW);
     digitalWrite(stepperPins[3], HIGH);
     delay(delayTime);
     }
     ch='x';dec=0;
  }
  else{
    if(Serial.available()){
    count = 0;
    while (Serial.available()) {
        ch = Serial.read();
        if(isdigit(ch)){
          digits[count] = ch-'0';
          count++;
          }
      }    
   }
  }
}
