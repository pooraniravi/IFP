//final transmitter side code of first dustbin
#include <SoftwareSerial.h>
SoftwareSerial xBeep(7,8);
int trig=9;
int echo=10;
int trig1=11;
int echo1=12;
float dur, dist;
float dur1, dist1;

void setup()
{
  Serial.begin(9600);
  //pinMode(4,INPUT);
  xBeep.begin(9600);
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT); 
  pinMode(trig1, OUTPUT); 
  pinMode(echo1, INPUT); 
  pinMode(2, OUTPUT); 
}
void ultrasonic()
{
  
 digitalWrite(trig, 0);
  delayMicroseconds(2);
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);
   dur = pulseIn(echo, 1);
  dist = (dur * (0.034 / 2));
}
void ultrasonic1()
{
  
  digitalWrite(trig1, 0);
  delayMicroseconds(2);
  digitalWrite(trig1, 1);
  delayMicroseconds(10);
  digitalWrite(trig1, 0);
   dur1 = pulseIn(echo1, 1);
  dist1 = (dur1 * (0.034 / 2));
}

void loop()
{
  ultrasonic();
  Serial.print("first sensor    ");
  Serial.println(dist);
  ultrasonic1();
  Serial.print("second sensor    ");
  Serial.println(dist1);
  delay(1000);
  if((dist<=15)&&(dist1<=15))
  {
    delay(5000);
    if((dist<=15)&&(dist1<=15))
    {
      Serial.println("DUSTBIN 1 IS FULL");
      xBeep.write("1");
      digitalWrite(2,HIGH);
      delay(1000);
    }
  }
  digitalWrite(2,LOW);
}
