String readdata;

void setup(){
  Serial.begin(91200);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
}

void loop(){
while (Serial.available()){
  delay(10);
  char c=Serial.read();
  readdata=c;
 
 
 
  Serial.println(readdata);}

 if(readdata=='F')
 {
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
 delay(100);
 }
else if (readdata=='B')
{
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  delay(100);
}
else if(readdata=='R')
{
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  delay(100);
}
else if (readdata=='L')
{
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  delay(100);
}
else if(readdata=='S')
{
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  delay(100);
}

}
