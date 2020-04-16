//dc motors delay test with lema battery 6.5 v
void left()
{
  digitalWrite(2, HIGH);
  digitalWrite(3,LOW );
  digitalWrite(4, LOW);
  digitalWrite(7, HIGH);
}

void right()
{
  digitalWrite(8, LOW);
  digitalWrite(9,HIGH );
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void up()
{
  digitalWrite(8, HIGH);
  digitalWrite(9,LOW );
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void down()
{
  digitalWrite(8, LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}
void Stop()
{
  digitalWrite(2, LOW);
  digitalWrite(3,LOW);
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
}

void setup() {
  // put your setup code here, to run once:
 //pinMode(4, INPUT);
  //pinMode(2, INPUT);
  //pinMode(3, INPUT);
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);  
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //up();
  //delay(2000);
  left();
  delay(1250);
//   Stop();
//  delay(200);
  //left();
  //delay(1000);
//   Stop();
//  delay(200);
//  down();
//  delay(2000);
  while(1)
  {
    Stop();
  }
}
