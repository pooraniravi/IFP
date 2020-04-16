//final reciever side code to communicate with dustbins 
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
#include<SoftwareSerial.h>
SoftwareSerial xBeep(8,9);

void setup()
{
  Serial.begin(9600);
  xBeep.begin(9600);
  lcd.begin(16,2);
  pinMode(A0,OUTPUT);
  //pinMode(6,OUTPUT);
  lcd.clear();
  lcd.print("Hi everyone!");
  delay(1000);
  lcd.clear();
  lcd.print("Have a good day!");
  delay(1000);
}
void loop()
{
Serial.println("hi");
while(!xBeep.available());
char c=xBeep.read();
delay(200);
Serial.println(c);
if(c== '1')
{ 
  lcd.clear();
Serial.println("Dustbin 1 is FULL");
lcd.print("Bin 1 is FULL");
delay(500);
digitalWrite(A0,HIGH);
delay(2000);
digitalWrite(A0,LOW);
delay(2000);
lcd.clear();
  }
if(c== '2')
  { 
    lcd.clear();
    Serial.println("Dustbin 2 is FULL");
lcd.print("Bin 2 is FULL");
delay(500);
digitalWrite(A0,HIGH);
delay(2000);
digitalWrite(A0,LOW);
delay(2000);
lcd.clear();
  }
}

