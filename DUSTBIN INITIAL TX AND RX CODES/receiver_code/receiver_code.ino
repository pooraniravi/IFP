//receiver
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
 // pinMode(5,OUTPUT);
  //pinMode(6,OUTPUT);
  lcd.clear();
  lcd.print("hi");
  delay(200);
}
void loop()
{
//  while(!Serial.available());
//  char c=Serial.read();
//  //Serial.print(c);
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

