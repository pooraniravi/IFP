int trig=3;
int echo=4;
void setup()
{
  Serial.begin(9600);
pinMode(trig, OUTPUT); 
pinMode(echo, INPUT); 
pinMode(13, OUTPUT); 
}

void loop()
{
int duration, distance;
digitalWrite(trig,HIGH);
delay(1);
digitalWrite(trig,LOW);
duration = pulseIn(echo,HIGH); // gives time for which pulse is high in microseconds
distance = (duration/2)/29.1; // gives dist in cm...... dist= (time/2)* speed...... speed= 0.0343 cm/microsec.....
// if distance less than 0.5 meter and more than 0 (0 or less means over range)
Serial.println(distance);
if (distance <= 5 && distance >= 0) 
digitalWrite(13, HIGH);
else 
digitalWrite(13, LOW);
// Waiting 60 ms won't hurt any one
delay(60);
}
