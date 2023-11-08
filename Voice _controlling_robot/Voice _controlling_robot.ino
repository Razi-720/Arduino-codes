#include<Servo.h>
int motor1pin1=2;
int motor1pin2=3;
int motor2pin1=4;
int motor2pin2=5;

Servo Myservo;
int pos;
void setup()
{
  pinMode(motor1pin1,OUTPUT);
  pinMode(motor1pin2,OUTPUT);
  pinMode(motor2pin1,OUTPUT);
  pinMode(motor2pin2,OUTPUT);
  Myservo.attach(9);
  Serial.begin(9600);
}
void loop()
{
  if(Serial.available()>0)
  {
    
    char ch= Serial.read();
    Serial.println(ch);
  if(ch=='f'){fwd();}
  else if(ch=='b'){back();}
  else if(ch=='l'){left();}
  else if(ch=='r'){right();}
  else if(ch=='s'){stop1();}
  else if(ch=='u'){up();}
  else if(ch=='d'){down();}
  }
}
void fwd()
{
  digitalWrite(motor1pin1,HIGH);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin1,HIGH);
  digitalWrite(motor2pin2,LOW);
  delay(10);
}
void back()
{
  digitalWrite(motor1pin1,LOW);
  digitalWrite(motor1pin2,HIGH);
  digitalWrite(motor2pin1,LOW);
  digitalWrite(motor2pin2,HIGH);
  delay(10);
}
void up()
{
  for(pos=0;pos<=30;pos++)
  {
    Myservo.write(pos);
 
  }
}
void left()
{
  digitalWrite(motor1pin1,HIGH);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin1,LOW);
  digitalWrite(motor2pin2,LOW);
  delay(10);
  
}
void right()
{
  digitalWrite(motor1pin1,LOW);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin1,HIGH);
  digitalWrite(motor2pin2,LOW);
  delay(10);
}
void stop1()
{
  digitalWrite(motor1pin1,LOW);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin1,LOW);
  digitalWrite(motor2pin2,LOW);
  
}
void down()
{
  for(pos=30;pos>=0;pos--)
  {
    Myservo.write(pos);
    delay(45);
  }
}
