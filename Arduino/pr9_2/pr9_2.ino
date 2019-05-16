#include <IRremote.h>      
#include <Servo.h>
#define plus 0xFFA857
#define minus 0xFFE01F 

int RECV_PIN = 7;       
Servo servo;
int val;                
bool left, right;  

IRrecv irrecv(RECV_PIN);

decode_results results;
unsigned long key_value = 0;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); 
  servo.attach(9);     
}

void loop() 
{
  if (irrecv.decode(&results)){
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;
          switch(results.value){         
            case 0xFFE01F:
            right = !right; 
            left = false;
            break;  
            case 0xFFA857:
            left = !left;     
            right = false; 
            break;  
          }
          key_value = results.value;
          irrecv.resume(); 
          }
        if (left && (val != 90))  {
            val++;                        
          }
        if (right && (val != 0))  {
            val--;                        
          }
  servo.write(val);
  delay(10);          
}
