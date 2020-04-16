//johnson test prog
int wheel_fl = 2;
int wheel_fr = 3;
int wheel_bl = 4;
int wheel_br = 5;
int fdelay = 4000;
int tdelay = 2000;

void front()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW );
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}
void back()
{
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  analogWrite(12, 255);
  analogWrite(11, 255);
}
void loop()
{

  front();
  delay(fdelay);
 
}
