//transmitter for rssi 
#include<SoftwareSerial.h>
SoftwareSerial xbeep(4,5);
void setup()
{
  Serial.begin(9600);
  xbeep.begin(9600);
  //pinMode(4,INPUT);
  //pinMode(5,INPUT);
}
void loop()
{
  //if((digitalRead(4)==0)&&(digitalRead(5)==0))
  //{
    //delay(5000);
    //if((digitalRead(4)==0)&&(digitalRead(5)==0))
    //{
      Serial.print("a");
      xbeep.print("a");
      delay(500);
    //}
  //}
}


