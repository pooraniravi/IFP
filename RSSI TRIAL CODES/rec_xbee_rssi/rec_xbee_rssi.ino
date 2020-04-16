//receiver
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
//#include<SoftwareSerial.h>
//SoftwareSerial xbeea(4,5);
void setup()
{
  Serial.begin(9600);
  //xbeea.begin(9600);
  lcd.begin(16,2);
  //pinMode(5,OUTPUT);
  pinMode(6,INPUT);
  //pinMode(13,OUTPUT);
  lcd.clear();
  lcd.print("hi");
  delay(2000);
}
void loop()
{
  //while(!xbeea.available());
  char c=Serial.read();
  int rssip=pulseIn(6,LOW,200);
  //digitalWrite(13,HIGH);
  //delay(1000);
  //digitalWrite(13,LOW);
  lcd.clear();
  lcd.print(c);
  delay(200);
  Serial.print(rssip);
  delay(2000);
 // delay(500);
//  if(c=='F')
//  { 
//    digitalWrite(5,HIGH);
//    delay(500);
//    digitalWrite(5,LOW);
//    delay(200);
//    lcd.clear();
//    lcd.print("dustbin 1 is full");
//    delay(500);
//  }
//  if(c=='R')
//  { 
//    digitalWrite(6,HIGH);
//    delay(500);
//    digitalWrite(6,LOW);
//    delay(200);
//    lcd.clear();
//    lcd.print("dustbin 2 is full");
//    delay(500);
//  }
}




