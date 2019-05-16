 #include <IRremote.h>
#include <LiquidCrystal.h>

const int RECV_PIN = 7;
String count[] = {"0","1","2","3","4","5","6","7","8","9"};
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

void setup(){
  
  Serial.begin(9600);
  irrecv.enableIRIn(); 
  irrecv.blink13(true);
  lcd.begin(16, 2);
}

void loop(){
  if (irrecv.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
        results.value = key_value;
        lcd.setCursor(0, 0);
        lcd.clear();
        
        switch(results.value){
          case 0xFF6897:
          lcd.print("0");
          break ;  
          
          case 0xFF30CF:
          for (int i = 1;i>0;i--){
            lcd.print(count[i]);
            delay(1000);
            lcd.setCursor(0, 0);
            lcd.clear();
          }
          break ;
          case 0xFF18E7:
          for (int i = 2;i>0;i--){
            lcd.print(count[i]);
            delay(1000);
            lcd.setCursor(0, 0);
            lcd.clear();
          }
          break ;
          
          case 0xFF7A85:
          for (int i = 3;i>0;i--){
            lcd.print(count[i]);
            delay(1000);
            lcd.setCursor(0, 0);
            lcd.clear();
          }
          break ;
          
          case 0xFF10EF:
          for (int i = 4;i>0;i--){
            lcd.print(count[i]);
            delay(1000);
            lcd.setCursor(0, 0);
            lcd.clear();
          }
          break ;
          
          case 0xFF38C7:
          for (int i = 5;i>0;i--){
            lcd.print(count[i]);
            delay(1000);
            lcd.setCursor(0, 0);
            lcd.clear();
          }
          break ;
          
          case 0xFF5AA5:
          for (int i = 6;i>0;i--){
            lcd.print(count[i]);
            delay(1000);
            lcd.setCursor(0, 0);
            lcd.clear();
          }
          break ;
          
          case 0xFF42BD:
          for (int i = 7;i>0;i--){
            lcd.print(count[i]);
            delay(1000);
            lcd.setCursor(0, 0);
            lcd.clear();
          }
          break ;
          
          case 0xFF4AB5:
          for (int i = 8;i>0;i--){
            lcd.print(count[i]);
            delay(1000);
            lcd.setCursor(0, 0);
            lcd.clear();
          }
          break ;
          
          case 0xFF52AD:
          for (int i = 9;i>0;i--){
            lcd.print(count[i]);
            delay(1000);
            lcd.setCursor(0, 0);
            lcd.clear();
          }
          break ;                   
        }
        key_value = results.value;
        irrecv.resume(); 
  }
}
