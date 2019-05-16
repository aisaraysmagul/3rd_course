String s;
void setup() {
  Serial.begin(9600);
}

void loop() {
  //#1
  delay(1000);
  String A = "sad";
  String B = "2";
  for(int i = 0;i<B.toInt();i++){
    //Serial.println(A);
  }
  
  //#2
  char s1[] = "left";
  char s2[] = "right";
  //compareStr(s1, s2);
  
  //#3
  int arrr[] = {2,4,5,6,7,8,22,23,12,0};
  //min_max(arrr, 10);
  
  //#4
  //int n = Serial.parseInt();
  //fib(n);

  //#5
  //readd(n1,arr);
  /*if(Serial.available()){
      int n1 = Serial.parseInt();
      Serial.print("took n");
      Serial.println(n1);
      int arr[n1];
      int a = 0;
      while(n1>0){
        if(Serial.available()){
          int m = Serial.parseInt();
          arr[a] = m;
          Serial.print("took m");
          Serial.println(m);
          a+=1;
          n1-=1;
        }
      }
      readd(n1, arr);
  }
  delay(1000);*/
  

  //#6
  /*int incomingByte; 
  if (Serial.available() > 0) {   
    char val = Serial.read();
    Serial.println(val, DEC);
  }*/

  //#7
  while (Serial.available()) {
    char ch = Serial.read();
    s += ch;
  }
  delay(500);
  if(s!= ""){
    Serial.println(s.substring(0, s.length()-1)+"-OK");}
    s = "";
}

void compareStr(char s1[], char s2[]){
  if(strcmp(s1, s2) == 0){
    Serial.println("strings are equal");
  }
  else{
    Serial.println("strings are NOT equal");
    }
}

void min_max(int arr[], int len){
  int mini = arr[0];
  int maxi = arr[0];
  for(int j=0;j<len;j++){
    if (arr[j]<mini){mini = arr[j];}
    if (arr[j]>maxi){
      maxi = arr[j];}
  }
  Serial.print("Minimum is ");
  Serial.println(mini);
  Serial.print("Maximum is ");
  Serial.println(maxi);
}

void fib(int n) 
{ 
   if(n>=3){
     float fib[n];
     fib[0] = 1;
     fib[1] = 1;
     for(int i = 2; i<n; i++){
       fib[i]=fib[i-2]+fib[i-1];
       Serial.println(fib[i]);
       } 
   }
} 

void readd(int n, int s[]){
  Serial.println("sorting");
  for (int j = 0;j<2;j++){
    for (int i = 0;i<3-i+1;i++){
      if (s[i]>s[i+1]){
        int t = s[i];
        s[i] = s[i+1];
        s[i+1] = t;
      }
    }
  }
  for (int i = 0;i<3;i++){
    Serial.println(s[i]);
    delay(500);
   }
   Serial.println("finish");
}
