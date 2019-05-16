int myPins[] = {2,4,6,4};
int del[] = {5000,1000,5000,5000};
void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  for (int i = 0; i < 4;i++){
      if (i == 2){
        digitalWrite(myPins[i], HIGH);   
        delay(4000);                  
        digitalWrite(myPins[i], LOW); 
        for (int j = 0;j<4;j++){
          delay(50); 
          digitalWrite(myPins[i], HIGH); 
          delay(200); 
          digitalWrite(myPins[i], LOW);
        }
      }
      else{
        digitalWrite(myPins[i], HIGH);   
        delay(del[i]);                  
        digitalWrite(myPins[i], LOW);
      }
  }
}
