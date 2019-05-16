#include <LiquidCrystal.h>

byte car[8]={
    B00000,
    B00000,
    B10100,
    B11110,
    B11110,
    B10100,
    B00000,
    B00000
};
byte obst[8]={
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111
};
byte truck[8]={
    B00000,
    B00000,
    B00000,
    B10100,
    B11110,
    B10100,
    B00000,
    B00000
};

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int startPin = 6;
const int jump=8;
const int fire=9;
int start=0;

//set buttonstates
bool jumpState=0;
bool fireState=0;
//random number for position of obstacles
int randomNums[6];
//random number for number of obstacles
int randomNum=0;
//random number for position of pts
int randomNums1[3];
//random number for number of pts
int randomNum1=0;
//made this boolean to check if button2 is pressed because if it's pressed once in the first for loop i want obstacles not to be written until the end of it
bool temp=0;
//this variable stores the positions of the car while he shoots. there can be 16 positions because the warrior has 16 positions.
int tempI[16];
//i use this boolean to check if the point is catched
bool temp1=0;
bool str = false;
int curr = 0;
//use this variable to store the position of the catched point. it must be and array to store the position of all the points in one iteration of the first for loop. if it stored just one position, then the "old" point would come back in the new iteration
int tempI1[16]; 
//use this variable to have a number of shots of the car, which is also the length of an array tempI
int fireIsPressed=0;
int fireIsPressed1=0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // set buttonpin mode
  pinMode(jump,INPUT);
  pinMode(fire,INPUT);
  lcd.createChar(1, car);
  lcd.createChar(2, obst);
  lcd.createChar(3, truck);
  lcd.begin(16,2);
  lcd.setCursor(0, 0);
  lcd.print("Car Racing");
  lcd.setCursor(0, 1);
  lcd.print("Press to start");
}

void loop() {
  start=digitalRead(startPin);
  if (start==HIGH){ str = true;}
  while(str){
    here:
    randomNum=random(2, 8);
    for(int i=0; i<randomNum; ++i){randomNums[i]=random(16);}
    randomNum1=random(1,4);
    for(int i=0; i<randomNum1; ++i){randomNums1[i]=random(16);}
    //i reset temp variable before every new for loop because the cycle of the moving car starts again
    temp=0;
    temp1=0;
    fireIsPressed=0;
    fireIsPressed1=0;
    //loop that writes car on the lcd which jumps everytime button is pressed
    for(int i=0; i<16; ++i){
           jumpState=digitalRead(jump);
           fireState=digitalRead(fire);
           if(!temp){
                for(int j=0; j<randomNum; ++j){
                    lcd.setCursor(randomNums[j],1);
                    lcd.write(2);
                 }
           }
           //checking if the car had shot but there were obstacles before him, we want those obstacles to stay 
           else{
            for(int j=0; j<randomNum; ++j){
           //i check only the tempI[0] position because that's the when the car shot for the first time and he removed all the remaining obstacles 
              if(tempI[0]>randomNums[j]){
                lcd.setCursor(randomNums[j],1);
                lcd.write(2);
                }
              }
            }        
          if(!temp1){
                    for(int j=0; j<randomNum1; ++j){
                      lcd.setCursor(randomNums1[j],0);
                      lcd.write(3);
                 }
           }
           //checking if the car had shot but there were trucks before him, we want those obstacles to stay 
           else{
            for(int j=0; j<randomNum1; ++j){
           //i check only the tempI1[0] position because that's the when the car shot for the first time and he removed all the remaining trucks 
              if(tempI1[0]>randomNums1[j]){
                lcd.setCursor(randomNums1[j],0);
                lcd.write(3);
                }
              }
            }
            //if the button is pressed we set the cursor up (so that our car jumps)
            if(jumpState==HIGH) {
              curr = !curr;
            }
            lcd.setCursor(i,curr);
            lcd.write(1);
           
            //if fire button is pressed our car shoots. i had to put this loop here so that car shoots from his current spot and then continues to move.
             if (fireState==HIGH){
              if (curr == 1){
                temp=1;
                //if the jump button is low then we remove all the obstacles. that's why the state if temp variable is changed
                if(jumpState==LOW) {tempI[fireIsPressed]=i;}
                ++fireIsPressed;
                Serial.println(fireIsPressed);
                for(int k=i+1; k<16; ++k){
                    lcd.setCursor(k,curr);
                    lcd.print("~");
                    delay(5);
                    
                    lcd.setCursor(k-1,curr); 
                    lcd.print(" ");
                    delay(5);
                }
              }else{
                temp1=1;
                //if the jump button is low then we remove all the trucks. that's why the state if temp1 variable is changed
                if(jumpState==LOW) {tempI1[fireIsPressed1]=i;}
                ++fireIsPressed1;
                for(int s=i+1; s<16; ++s){
                    lcd.setCursor(s,curr);
                    lcd.print("~");
                    delay(5);
                    
                    lcd.setCursor(s-1,curr); 
                    lcd.print(" ");
                    delay(5);
                }
              }
           }
            delay(500);
            lcd.clear();
             //checking if the positions of the truck and the car are the same then they collide it is the end of the game
            for(int l=0; l<randomNum1; ++l){
              if(i==randomNums1[l] && curr==0 && temp1==0){
                   lcd.clear();
                   lcd.setCursor(4,0);
                   lcd.print("GAME OVER");
                   lcd.setCursor(1,1);
                   lcd.print("Wait 3 seconds");
                   delay(3000);
                   lcd.clear();
                   //i must skip the for loop because otherwise the game would continue where it ended
                   goto here;
                 }
             }
            //checking if the positions of the obstacle and the car are the same then they collide and it is the end of the game
         for(int j=0; j<randomNum; ++j){
           if(i==randomNums[j] && curr==1 && temp==0) {
               lcd.clear();
               lcd.setCursor(4,0);
               lcd.print("GAME OVER");
               lcd.setCursor(1,1);
               lcd.print("Wait 3 seconds");
               delay(3000);
               lcd.clear();
               goto here;
           }
          }  
        }
      }
}
