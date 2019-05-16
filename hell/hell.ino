#include <SoftwareSerial.h>

//+CIPTA:ip:"172.20.10.2"


SoftwareSerial wifiSerial(9,10); // TX, RX
const String collection[38] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",".","0","1","2","3","4","5","6","7","8","9"," "};
String s="";
bool ass=false;
String strs="";
const byte matrix[38][8] = {
    {0,0,0,1,0,0,0,1}, // a
    {1,1,0,0,0,0,0,1}, // b
    {0,1,1,0,0,0,1,1}, // c
    {1,0,0,0,0,1,0,1}, // d
    {0,1,1,0,0,0,0,1}, // e
    {0,1,1,1,0,0,0,1}, // f
    {0,0,0,0,1,0,0,1}, // g
    {1,0,0,1,0,0,0,1}, // h
    {1,1,1,1,0,0,1,1}, // i
    {1,0,0,0,0,1,1,1}, // j
    {1,0,0,1,0,0,0,1}, // k
    {1,1,1,0,0,0,1,1}, // l
    {0,1,0,1,0,1,1,1}, // m
    {1,1,0,1,0,1,0,1}, // n
    {0,0,0,0,0,0,1,1}, // o
    {0,0,1,1,0,0,0,1}, // p
    {0,0,0,1,1,0,0,1}, // q
    {1,1,1,1,0,1,0,1}, // r
    {0,1,0,0,1,0,0,1}, // s
    {1,1,1,0,0,0,0,1}, // t
    {1,0,0,0,0,0,1,1}, // u
    {1,1,0,0,0,1,1,1}, // v
    {1,0,1,0,1,0,1,1}, // w
    {1,0,0,1,0,0,0,1}, // x
    {1,0,0,0,1,0,0,1}, // y
    {0,0,1,0,0,1,0,1}, // z
    {1,1,1,1,1,1,1,0}, // .
    {0,0,0,0,0,0,1,1}, // 0
    {1,0,0,1,1,1,1,1}, // 1
    {0,0,1,0,0,1,0,1}, // 2
    {0,0,0,0,1,1,0,1}, // 3
    {1,0,0,1,1,0,0,1}, // 4
    {0,1,0,0,1,0,0,1}, // 5
    {0,1,0,0,0,0,0,1}, // 6
    {0,0,0,1,1,1,1,1}, // 7
    {0,0,0,0,0,0,0,1}, // 8
    {0,0,0,0,1,0,0,1}, // 9
    {1,1,1,1,1,1,1,1} // " "
}; 

const int segmentPins[8] = {A0,2,3,5,6,8,7,4};
const int digitPins[4] = {A5,11,12,13};

const int bPrev   = A1;
const int bNext   = A2;
const int bMode   = A3;
const int bChange = A4;

int next=0, notnext=0, prev=0, notprev=0, mode=0, notmode=0, change=0, notchange=0;
String str = "";  //message sented, message received
int np = 0; //how many times you can press buttons bNext, bPrev in received mode
int nach=0; // with which index you should start to show on display
int ch = 0; // on which index of message we press bChange in senting mode
int arr[25]; // for filling with indexes of collection (for ex max nb of message length is 50)
bool rec = true; // to identify receiving or senting mode
int letter = 0; // index of collection in senting mode
int sent = 1; //len of sending message

void setup() {
  Serial.begin(115200);
  wifiSerial.begin(115200); //can't be faster than 115200
  wifiSerial.setTimeout(5000);
  String res="";
 
  wifiSerial.println("AT+RST");
   
  wifiSerial.println("AT+CWMODE=1");
  delay(1000);
  String cmd = "AT+CWJAP=\"";
  cmd += "Humanoiddess";
  cmd += "\",\"";
  cmd += "human123";
  cmd += "\"";
  delay(1000);
  wifiSerial.println(cmd);
  delay(3000);
  wifiSerial.println("AT+CWDHCP=1,1");
  delay(3000);
  wifiSerial.println("AT+CIPMUX=1");
  delay(1000);
  wifiSerial.println("AT+CIPSERVER=1,2222");
  Serial.println("wifi is ready!");
  for(int i=0; i < 8; i++)
    pinMode(segmentPins[i], OUTPUT);
  for(int i=0; i < 4; i++)
    pinMode(digitPins[i], OUTPUT);
  pinMode(bNext, INPUT);
  pinMode(bPrev, INPUT);
  pinMode(bMode, INPUT);
  pinMode(bChange, INPUT);
  empty();
  
}

void loop() {

  next = digitalRead(bNext);
  prev = digitalRead(bPrev);
  mode = digitalRead(bMode);
  change = digitalRead(bChange);

  for (int i=0;i<4;i++){
    show(arr[i+nach],i);
  }
  
  //RECEIVING MODE
  
  if(rec){
    if (wifiSerial.available()){
      empty();
      while(wifiSerial.available()){
        s = (char)wifiSerial.read();
        if (s==":"){
          ass=true;
        }
        if(ass){
          for (int i=0;i<25;i++){
            strs += (char)wifiSerial.read();
            delay(100);}
        }
      }
      if (strs!="") {
        Serial.println(strs);
        strs.toLowerCase();
        np = strs.length()-4;
        nach = 0;
        if (strs.length()>25){
          error();
          np = 1;
        }
        else{
          for (int i=0;i<strs.length();i++){
            for (int j=0;j<38;j++){
              if (String(strs.charAt(i))==collection[j]){
                arr[i] = j;
                Serial.print(i);
                Serial.print('-');
                Serial.println(j);
              }
            }
          }
        }
      }

      ass = false;
      strs="";
      
    }
    if(mode != notmode){
      if  (mode==1){
        ch = 0;
        letter = 0;
        rec = !rec;
        empty();
      }
    }  

    if(next!=notnext){
      if(next == 1){
        if(nach < np){
          nach++;
        }   
      }
    }

    if(prev!=notprev){
      if(prev == 1){
        if(nach > 0){
          nach--;
        }
      }
    }
  }

  //SENDING MODE
  else{
    if(mode != notmode){
      if (mode==1){
        nach = 0;
        str = "";
        
        for (int i =0;i <sent;i++){
          str = str + collection[arr[i]];
        }
        if (str!=""){
          wifiSerial.println("AT+CIPSEND=0,10");
          delay(500);
          wifiSerial.println(str);
          wifiSerial.println("");
          wifiSerial.println("");
        }
        empty();
        rec = !rec;
      }
    }
    

    if(next!=notnext){
      if(next == 1){
        letter = 0;
        ch++;
        sent++;
        if(ch>3){
          nach++;  
        }
      }
    }
   
    if(prev!=notprev){
      if(prev == 1){
        nach =  0;
        ch=0;
        letter = 0;
        empty();
      }
    }
    if (change != notchange){
      if(change == 1){
        arr[ch] = letter;
        if (letter == 37){
          letter = 0;
        }
        letter++;
      }
    }
  }
  
  
 notmode = mode;
 notnext = next;
 notprev = prev;
 notchange = change;
    
    
}
void show(int zet, int i){
  for(int j = 0; j < 8; j++)
    digitalWrite(segmentPins[j], matrix[zet][j]);  
  digitalWrite(digitPins[i],HIGH);
  delay(1);
  digitalWrite(digitPins[i],LOW);
}
void empty(){
  for(int i = 0; i < 25; i++)
    arr[i] = 37;
}
void error(){
  arr[0]=4;
  arr[1]=17;
  arr[2]=17;
  arr[3]=14;
  arr[4]=17;
}
