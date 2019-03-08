#define echoPin 7
#define buzz 9
#define trigPin 4
int sensor=3;
long sampletime=1000;

void setup() {
 Serial.begin(9600);
  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buzz,OUTPUT);

}

void loop() {
 int rpm=getrpm();
 Serial.println(rpm);
  long duration,distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=(duration/2)/29.1;
  if (distance<(50+(rpm/10)))
  {
    digitalWrite(buzz,HIGH);
  }
  else{
    digitalWrite(buzz,LOW);
    }
    Serial.print(distance);
    Serial.print("cms\n");
}

  int getrpm(){
  int count=0;
  boolean flag=LOW;
  long ct=0,st=millis();
  while (ct<=sampletime){
    if(digitalRead(sensor)==HIGH)
    {flag=HIGH;}
    if(digitalRead(sensor)==LOW && flag==HIGH){
      count++;
      flag=LOW;
      }
      ct=millis()-st;
    }
  int rpm=(int(60000/float(sampletime))*count)/20;
  return rpm;
}
