void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  //#1
  String namee = "Aisara";
  namee.concat(" ");
  namee.concat("Ysmagul");
  //Serial.println(namee);
  //#2
  String text = "asbdjhasd asndk asjdn asdn";
  int count = 0;
  for (char i:text){
    if (i==' '){
      count++;
    }
  }
  //Serial.println(count);
  //#3
  String s = "Name Surname Age";
  int start = 0;
  for (int i = 0;i<s.length();i++){
    if (s.charAt(i)==' '){
      //Serial.println(s.substring(start, i));
      start = i+1;
    }
  }
  //Serial.println(s.substring(start, s.length()));
  //#4
  String s2 = "2dsfds4ef345ef";
  for(char i: s2){
    if(isDigit(i)){
      //Serial.println(i);
    }
  }
  //#5
  //Serial.println(compare(3,4));
  //#6
  int arrr[] = {2,4,5,6,7,8,22,23,12,0};
  //Serial.println(minimum(arrr, 10));
  //#7
  int ar[] = {1,6,7,2};
  //sortt(ar, 4);
  //#8
  int n = Serial.read()-'0';
  Serial.println(n);
  for (int i=0;i<int(n);i++){
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
  }
  delay(1000);
}
int compare(int a, int b){
  if (a < b){return (-1);}
  else if(a>b){return (1);}
  else {return (0);}
}

int minimum(int arr[], int len){
  int m = arr[0];
  for(int j=0;j<len;j++){
    if (arr[j]<m){m = arr[j];}
  }
  return m;
}

void sortt(int arr[], int len){
  for (int j = 0;j<len-1;j++){
    for (int i = 0;i<len-i+1;i++){
      if (arr[i]>arr[i+1]){
        int t = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = t;
      }
    }
  }
  for (int i = 0;i<len;i++){
    //Serial.println(arr[i]);
    //delay(1000);
   }
}
