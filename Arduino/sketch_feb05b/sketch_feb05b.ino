int red = 2;
int yellow = 4;
int green = 6;

void setup(){
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
}

void loop(){
    changeLights();
    delay(1000);
}

void changeLights(){
    // turn off yellow, then turn red on for 5 seconds
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    delay(5000);

    // red and yellow on for 2 seconds (red is already on though)
   digitalWrite(red,LOW);
    digitalWrite(yellow, HIGH);
    delay(1000);

    // turn off red and yellow, then turn on green
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
    delay(4000);
   
   digitalWrite(green, LOW); 
 delay(50); 
 digitalWrite(green, HIGH); 
 delay(200); 
   digitalWrite(green, LOW); 
 delay(50); 
 digitalWrite(green, HIGH); 
 delay(200); 
   digitalWrite(green, LOW); 
 delay(50); 
 digitalWrite(green, HIGH); 
 delay(200); 
   digitalWrite(green, LOW); 
 delay(50); 
 digitalWrite(green, HIGH); 
 delay(200); 
 
   
   digitalWrite(green,LOW);
   digitalWrite(yellow, HIGH);
   delay(5000); 
}
