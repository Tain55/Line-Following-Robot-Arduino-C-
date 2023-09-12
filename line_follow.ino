
// C++ code
//

int In1 =7;///motor 1
int In2 =8;

int In3 =11; //motor2
int In4 =12;

int En1=9; //Enable pin 1
int En2=10;   //Enable pin 2

int S1=2;
int S2=3;
int S3=4;
int S4=5;
int S5=6;    // Sensor pin

int s1,s2,s3,s4,s5; //Sensor Data

void setup()
{
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(En1, OUTPUT);
  pinMode(En2, OUTPUT);
  
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  
  Serial.begin(9600);
  
  analogWrite(En1,255);
  analogWrite(En2,255);
  
}

void loop()
{
  s1=digitalRead(S1);
  s2=digitalRead(S2);
  s3=digitalRead(S3);
  s4=digitalRead(S4);
  s5=digitalRead(S5);
  
  
  Serial.print(s1);
  Serial.print(s2);
  Serial.print(s3);
  Serial.print(s4);
  Serial.println(s5);
  
  
  if (s1==1 && s2==1 && s3==0 && s4==1 && s5==1){
  forward();
  }
  if (s1==1 && s2==1 && s3==1 && s4==0 && s5==1){
  forward_right();
  }
  if (s1==1 && s2==0 && s3==1 && s4==1 && s5==1){
  forward_left();
  }
  
   else if (s1==1 && s2==1 && s3==1 && s4==1 && s5==0){
  right();
  }
  
  
   else if (s1==0 && s2==1 && s3==1 && s4==1 && s5==1){
  left();
  } 
  
   else if (s1==0 && s2==0 && s3==0 && s4==1 && s5==1){
  left();
  } 
  
   else if (s1==1 && s2==1 && s3==0 && s4==0 && s5==0){
  right();
  } 
  
  
  
  
  
  
}


int forward(){
  analogWrite(En1,60);
  analogWrite(En2,60);
  
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);

}

int forward_left(){
  analogWrite(En1,50);
  analogWrite(En2,53);
  
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);

}

int forward_right(){
  analogWrite(En1,53);
  analogWrite(En2,50);
  
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);

}


int back(){
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);

}

int left(){
  analogWrite(En1,50);
  analogWrite(En2,50);
  
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);

}

int right(){
  analogWrite(En1,50);
  analogWrite(En2,50);
  
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}

int stop(){
  analogWrite(En1,0);
  analogWrite(En2,0);
  
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}