//overall big bot actuations test
int wheel_fl=2;
int wheel_f2=3;
int wheel_f3=4;
int wheel_f4=5;
int wheel_b1=6;
int wheel_b2=7;
int wheel_b3=8;
int wheel_b4=9;
int wheel_e1=14;
int wheel_e2=15;
int wheel_e3=16;
int wheel_e4=17;

int rail_ll=44;
int rail_l2=45;
int rail_l3=46;
int rail_l4=47;
int rail_rl=50;
int rail_r2=51;
int rail_r3=52;
int rail_r4=53;

int frontraill1=22;
int frontraill2=23;
int frontrailr1=24;
int frontrailr2=25;

int backraill1=22;
int backraill2=23;
int backrailr1=24;
int backrailr2=25;

int em1=36;//electromagnets
int em2=37;
int em3=38;
int em4=39;

int s1=32;// servo motors
int s2=33;
int s3=34;
int s4=35;


int fdelay=6000;
int tdelay=2000;
int fdelayr=6000;
int updelay=200;
void left()
{
  digitalWrite(2, HIGH);
  digitalWrite(3,LOW );
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7,LOW );
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}

void right()
{
  digitalWrite(2, LOW);
  digitalWrite(3,HIGH );
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7,HIGH );
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}
void front()
{
  digitalWrite(2, HIGH);
  digitalWrite(3,LOW );
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7,LOW );
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}
void back()
{
  digitalWrite(2, LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}
void Stop()
{
  digitalWrite(2, LOW);
  digitalWrite(3,LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7,LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  
}
void storage_front()
{
  digitalWrite(44, HIGH);
  digitalWrite(45,LOW );
  digitalWrite(46, HIGH);
  digitalWrite(47,LOW);
  digitalWrite(50, HIGH);
  digitalWrite(51,LOW );
  digitalWrite(52, HIGH);
  digitalWrite(53,LOW);
}
void storage_back()
{
  digitalWrite(44, LOW);
  digitalWrite(45,HIGH);
  digitalWrite(46, LOW);
  digitalWrite(47, HIGH);
  digitalWrite(50, LOW);
  digitalWrite(51,HIGH);
  digitalWrite(52, LOW);
  digitalWrite(53, HIGH);
}
void frail_up()
{
  digitalWrite(22, HIGH);
  digitalWrite(23,LOW );
  digitalWrite(24, HIGH);
  digitalWrite(25, LOW);
}
void frail_down()
{
  digitalWrite(22, LOW);
  digitalWrite(23,HIGH);
  digitalWrite(24, LOW);
  digitalWrite(25, HIGH);
}
void brail_up()
{
  digitalWrite(22, HIGH);
  digitalWrite(23,LOW );
  digitalWrite(24, HIGH);
  digitalWrite(25, LOW);
}
void brail_down()
{
  digitalWrite(22, LOW);
  digitalWrite(23,HIGH);
  digitalWrite(24, LOW);
  digitalWrite(25, HIGH);
}
void setup() 
{
  pinMode(wheel_f1, OUTPUT);
  pinMode(wheel_f2, OUTPUT);
  pinMode(wheel_f3, OUTPUT);
  pinMode(wheel_f4, OUTPUT);
  pinMode(wheel_b1, OUTPUT);
  pinMode(wheel_b2, OUTPUT);
  pinMode(wheel_b3, OUTPUT);
  pinMode(wheel_b4, OUTPUT); //wheels
  
  pinMode(wheel_e1, OUTPUT);
  pinMode(wheel_e2, OUTPUT);
  pinMode(wheel_e3, OUTPUT);
  pinMode(wheel_e4, OUTPUT);//enable for wheels
  
  pinMode(rail_l1, OUTPUT);
  pinMode(rail_l2, OUTPUT);
  pinMode(rail_l3, OUTPUT);
  pinMode(rail_l4, OUTPUT);
  pinMode(rail_r1, OUTPUT);
  pinMode(rail_r2, OUTPUT);
  pinMode(rail_r3, OUTPUT);
  pinMode(rail_r4, OUTPUT);//storage rails
  
  pinMode(frontraill1, OUTPUT);
  pinMode(frontraill2, OUTPUT);
  pinMode(frontrailr1, OUTPUT);
  pinMode(frontrailr2, OUTPUT);//front rail

  pinMode(backraill1, OUTPUT);
  pinMode(backraill2, OUTPUT);
  pinMode(backrailr1, OUTPUT);
  pinMode(backrailr2, OUTPUT);//back rail

  pinMode(em1,OUTPUT);
  pinMode(em2,OUTPUT);
  pinMode(em3,OUTPUT);
  pinMode(em4,OUTPUT);//electromagnets
  
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(s4,OUTPUT);//servos
  
  digitalWrite(14,HIGH);
  digitalWrite(15,HIGH);
  digitalWrite(16,HIGH);
  digitalWrite(17,HIGH);//enable for wheels
  }
 void loop()
 {
  storage_front();
  delay(2000);
  storage_back();
  delay(2000);
  frail_up();
  delay(15500);
  frail_down();
  delay(11000);
  
 }
