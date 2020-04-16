//WAVEFRONT ALGORITHM TEST IN SERIAL MONITOR WHEN MATRIX IS PRE-FED
int nothing = 0;
int wall = 255;
int goal = 2;
int robot = 254;
int Map[6][6] = {{255, 255, 255, 255, 255, 255}, {255, 5, 4, 3, 2, 255}, {255, 6, 5, 4, 3, 255}, {255, 7, 6, 5, 4, 255}, {255, 254, 7, 6, 5, 255}, {255, 255, 255, 255, 255, 255}};
int robot_x = 4;
int robot_y = 1;
int goal_x = 1;
int goal_y = 4;
int x = 0;
int y = 0;
int a, b, c, d, e;
char directions[20];
int i=0;
void left()
{
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW );
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}

void right()
{
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH );
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void up()
{
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW );
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void down()
{
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}
void Stop()
{
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void scanp()
{
  a = Map[robot_x - 1][robot_y];
  b = Map[robot_x + 1][robot_y];
  c = Map[robot_x][robot_y - 1];
  d = Map[robot_x][robot_y + 1];
  e = min(a, min(b, min(c, d)));
  Serial.print("value of e = ");
  Serial.println(e);

  if (e == Map[robot_x][robot_y - 1])
  {
    robot_y = robot_y - 1;
    directions[i] = 'l';
    Serial.print("value in array");
    Serial.print(" ");
    Serial.println(directions[i]);
    Serial.println("value of i==");
    Serial.println(i);
    i++;
  }
  if (e == Map[robot_x][robot_y + 1])
  {
    robot_y = robot_y + 1;
    directions[i] = 'r';
    Serial.print("value in array");
    Serial.print(" ");
    Serial.println(directions[i]);
    Serial.println("value of i==");
    Serial.println(i);
    i++;
     }
  if (e == Map[robot_x - 1][robot_y])
  {
    robot_x = robot_x - 1;
    directions[i] = 'u';
    Serial.print("value in array");
    Serial.print(" ");
    Serial.println(directions[i]);
    Serial.println("value of i==");
    Serial.println(i);
    i++ ;
  }
  if (e == Map[robot_x + 1][robot_y])
  {
    robot_x = robot_x + 1;
    directions[i] = 'd';
    Serial.print("value in array");
    Serial.print(" ");
    Serial.println(directions[i]);
    Serial.println("value of i==");
    Serial.println(i);
    i++;
  }
  if ((Map[robot_x][robot_y]) == 2)
  {
    directions[i] = 's';
    Serial.print("value in array");
    Serial.print(" ");
    Serial.println(directions[i]);
    Serial.println("value of i==");
    Serial.println(i);
    i++;
  }
}
void loop()
{

  Serial.println("Robot coordinate");
  Serial.println((Map[robot_x][robot_y]));
  while ((Map[robot_x][robot_y] != 2))
  {
    int i;
    scanp();
  }
  Serial.print("pointer 0  =  ");
  Serial.println(directions[0]);
  Serial.print("pointer 1  =  ");
  Serial.println(directions[1]);
  Serial.print("pointer 2  =  ");
  Serial.println(directions[2]);
  Serial.print("pointer 3  =  ");
  Serial.println(directions[3]);
  Serial.print("pointer 4  =  ");
  Serial.println(directions[4]);
  Serial.print("pointer 5  =  ");
  Serial.println(directions[5]);
  Serial.print("pointer 6  =  ");
  Serial.println(directions[6]);
  Serial.print("pointer 7  =  ");
  Serial.println(directions[7]);
  Serial.print("pointer 8  =  ");
  Serial.println(directions[8]);
  Serial.print("pointer 9  =  ");
  Serial.println(directions[9]);
  Serial.print("pointer 10  =  ");
  Serial.println(directions[10]);

  while (1)
  {}
}
