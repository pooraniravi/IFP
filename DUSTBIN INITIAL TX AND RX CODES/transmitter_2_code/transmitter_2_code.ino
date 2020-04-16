//transmitter1
void setup()
{
  Serial.begin(9600);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
}
void loop()
{
  if((digitalRead(4)==0)&&(digitalRead(5)==0))
  {
    delay(5000);
    if((digitalRead(4)==0)&&(digitalRead(5)==0))
    {
      Serial.print('R');
    }
  }
}

