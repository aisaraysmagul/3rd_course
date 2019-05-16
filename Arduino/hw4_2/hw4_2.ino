const int ledPin2 = 8; 
const int ledPin3 = 13; 
const int input = 2; 
const int input1 = 3; 
const int input2 = 4; 
const int input3 = 5; 
const int input4 = 6; 
const int input5 = 7; 

int count = 0;
char pin[]="3333";
char pin2[]="";
int val1, val2, val3, val4, val5 = LOW;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin2, OUTPUT); 
  pinMode(ledPin3, OUTPUT); 
  pinMode(input, INPUT);
  pinMode(input1, INPUT);
  pinMode(input2, INPUT);
  pinMode(input3, INPUT);
  pinMode(input4, INPUT);
  pinMode(input5, INPUT);
}

void loop() {
  if(count<5){
   if(digitalRead(input)==HIGH){
    char one[] = "1";
    Serial.println(1);
    strcat(pin2,one);
    count ++;
    }
    if(digitalRead(input1)==HIGH){
      char two[] = "2";
      Serial.println(2);
      strcat(pin2, two);
      count++;
    }
    if(digitalRead(input2)==HIGH){
      char three[] = "3";
      Serial.println(3);
      strcat(pin2, three);
      count++;
    }
    if(digitalRead(input3)==HIGH){
      char four[] = "4";
      Serial.println(4);
      strcat(pin2, four);
      count++;
    }
    if(digitalRead(input4)==HIGH){
      char five[] = "5";
      Serial.println(5);
      strcat(pin2, five);
      count++;
    }
  }
  if(count==4){
   if(strcmp(pin, pin2)==0){
     digitalWrite(ledPin3, HIGH);
     count = 0;
     pin2[0] = "";
    }
    else{
      digitalWrite(ledPin2, HIGH);
      count = 0;
      pin2[0] = "";
      }
    }
}
