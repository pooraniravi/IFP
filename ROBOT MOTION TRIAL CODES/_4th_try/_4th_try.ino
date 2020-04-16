//WAVEFRONT ALGORITHM TEST IN SERIAL MONITOR WHEN MATRIX IS FILLED ON ITS OWN AND OBSTACLE DETECTION IS INCLUDED..UPGRADATION
int trig1 = 6;
int echo1= 7;
int trig2 = 8;
int echo2 = 9;
int trig3 = 10;
int echo3 = 11;
float dur1, dist1;
float dur2, dist2;
float dur3, dist3;

int fdelay=1350;
int tdelay=550;
int nothing=0;
int wall=255;
int goal=2;
int robot=254;
int Map[6][6]={{255,255,255,255,255,255},{255,0,0,0,0,255},{255,0,0,0,0,255},{255,0,0,0,0,255},{255,0,0,0,0,255},{255,255,255,255,255,255}};
int robot_x=4;
int robot_y=1;
int goal_x=1;
int goal_y=4;
int x=0;
int y=0;
int a,b,c,d,e;
int minimum_node=250;
int min_node_location=0;
int reset_min=250;
void left()
{
  digitalWrite(4, HIGH);
  digitalWrite(5,LOW );
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}

void right()
{
  digitalWrite(4, LOW);
  digitalWrite(5,HIGH );
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void up()
{
  digitalWrite(4, HIGH);
  digitalWrite(5,LOW );
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void down()
{
  digitalWrite(4, LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}
void Stop()
{
  digitalWrite(4, LOW);
  digitalWrite(5,LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}
void ultrasonic1()
{
  digitalWrite(trig1, 0);
  delayMicroseconds(2);
  digitalWrite(trig1, 1);
  delayMicroseconds(10);
  digitalWrite(trig1, 0);
  dur1 = pulseIn(echo1, 1);
  dist1 = (dur1 * (0.034 / 2));
}
void ultrasonic2()
{
  digitalWrite(trig2, 0);
  delayMicroseconds(2);
  digitalWrite(trig2, 1);
  delayMicroseconds(10);
  digitalWrite(trig2, 0);
  dur2 = pulseIn(echo2, 1);
  dist2 = (dur2 * (0.034 / 2));
}
void ultrasonic3()
{
  digitalWrite(trig3, 0);
  delayMicroseconds(2);
  digitalWrite(trig3, 1);
  delayMicroseconds(10);
  digitalWrite(trig3, 0);
  dur3 = pulseIn(echo3, 1);
  dist3 = (dur3 * (0.034 / 2));
}
void servo()
{
  ultrasonic1(); /////////////////////////////////////////////////////////////////////////////delay check
  Serial.print("dist at zero degree    ");
  Serial.println(dist1);
  if (dist1 < 30)
  {
    Map[robot_x][robot_y + 1] = 255;
    unpropagate(robot_x, robot_y);
    propagate_wavefront(robot_x, robot_y, goal_x, goal_y);
    mapprint();
  }
 
  ultrasonic2();
  Serial.print("dist at ninety degree    ");
  Serial.println(dist2);
  if (dist2 < 30)
  {
    Map[robot_x - 1][robot_y] = 255;
    unpropagate(robot_x, robot_y);
    propagate_wavefront(robot_x, robot_y, goal_x, goal_y);
    mapprint();
  }
  
  ultrasonic3();
  Serial.print("dist at 180 degree    ");
  Serial.println(dist3);
  if (dist3 < 30)
  {
    Map[robot_x][robot_y - 1] = 255;
    unpropagate(robot_x, robot_y);
    propagate_wavefront(robot_x, robot_y, goal_x, goal_y);
    mapprint();
  }
}
void mapprint() {
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      if (Map[i][j] == nothing)
        propagate_wavefront(robot_x, robot_y, goal_x, goal_y);
    }
  }
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      Serial.print(Map[i][j]);
      Serial.print(" ");
    }
    Serial.println();
  }
}
int propagate_wavefront(int robot_x, int robot_y, int goal_x, int goal_y)
  {
  //clear old wavefront
  
  
  //counter=0;//reset the counter for each run!
    //while(counter<50)//allows for recycling until robot is found
      //  {
        x=0;
        y=0;
      while(x<6 && y<6)//while the map hasnt been fully scanned
        {
        //if this location is a wall or the goal, just ignore it
        if (Map[x][y] != wall && Map[x][y] != goal)
          { 
          //a full trail to the robot has been located, finished!
          //if (min_surrounding_node_value(x, y) < reset_min && Map[x][y]==robot)
           // {
            //finshed! tell robot to start moving down path
           // return min_node_location;
            //}
          //record a value in to this node
          min_surrounding_node_value(x,y);
           if (minimum_node<reset_min && Map[x][y]!=robot)//if this isnt here, 'nothing' will go in the location
            Map[x][y]=minimum_node+1;
          }
        
        //go to next node and/or row
        y++;
        if (y==6 && x!=6)
          {
          x++;
          y=0;
          }
  //      }
//      counter++;
        }
    return 0;
  }

void unpropagate(int robot_x, int robot_y)//clears old path to determine new path
  {
  //stay within boundary
  for(x=0; x<6; x++)
    for(y=0; y<6; y++)
      if (Map[x][y] != wall && Map[x][y] != goal) //if this location is something, just ignore it
        Map[x][y] = nothing;//clear that space
  
  //store robot location in map
  Map[robot_x][robot_y]=robot;
  //store robot location in map
  Map[goal_x][goal_y]=goal;
  }

//if no solution is found, delete all walls from map
void clear_map(void)
  { 
  for(x=0;x<6;x++)
    for(y=0;y<6;y++)
      if (Map[x][y] != robot && Map[x][y] != goal)
        Map[x][y]=nothing;
  }

//this function looks at a node and returns the lowest value around that node
//1 is up, 2 is right, 3 is down, and 4 is left (clockwise)
int min_surrounding_node_value(int x, int y)
  {
  minimum_node=reset_min;//reset minimum

  //down
  if(x < 5)//not out of boundary
    if  (Map[x+1][y] < minimum_node && Map[x+1][y] != nothing)//find the lowest number node, and exclude empty nodes (0's)
        {
      minimum_node = Map[x+1][y];
      min_node_location=3;
            }

  //up
  if(x > 0)
    if  (Map[x-1][y] < minimum_node && Map[x-1][y] != nothing)
        {
      minimum_node = Map[x-1][y];
      min_node_location=1;
            }
  
  //right
  if(y < 5)
    if  (Map[x][y+1] < minimum_node && Map[x][y+1] != nothing)
        {
      minimum_node = Map[x][y+1];
      min_node_location=2;
            }
            
  //left
  if(y > 0)
    if  (Map[x][y-1] < minimum_node && Map[x][y-1] != nothing)
        {
      minimum_node = Map[x][y-1];
      min_node_location=4;
            }
     
  return minimum_node;
  }
void scanp()
{
d=Map[robot_x-1][robot_y];
c=Map[robot_x+1][robot_y];
a=Map[robot_x][robot_y-1];
b=Map[robot_x][robot_y+1];
e=min(a,min(b,min(c,d)));
Serial.print(e);
if(e==Map[robot_x][robot_y-1])
{  
  
  robot_y=robot_y-1;
  left();
  Serial.println("l");
  delay(tdelay);
  Stop();
  delay(2000);
  up();
  Serial.println("u");
  delay(fdelay);
  right();
  delay(tdelay);
  Stop();
    delay(2000);
  }
if(e==Map[robot_x][robot_y+1])
{
 robot_y=robot_y+1;
  right();
  Serial.println("r");
  delay(tdelay);
  Stop();
  delay(2000);
  up();
  Serial.println("u");
  delay(fdelay);
  Stop();
    delay(2000);
  left();
  delay(tdelay);
  Stop();
    delay(2000);
}
if(e==Map[robot_x-1][robot_y])
{
  robot_x=robot_x-1;
  up();
  Serial.println("u");
  delay(fdelay);
  Stop();
    delay(2000);
}
if(e==Map[robot_x+1][robot_y])
{
  robot_x=robot_x+1;
  down();
  Serial.println("d");
  delay(fdelay);
  Stop();
    delay(2000);
}
}

void setup() {
Serial.begin(9600);
 pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig1, OUTPUT);
   pinMode(echo2, INPUT);
  pinMode(trig2, OUTPUT);
   pinMode(echo3, INPUT);
  pinMode(trig3, OUTPUT);
  pinMode(12, OUTPUT);
  unpropagate(robot_x, robot_y);
  propagate_wavefront(robot_x,robot_y,goal_x,goal_y);
 mapprint();
}
 void loop()
 {
  servo();
 if(Map[robot_x][robot_y]!=Map[goal_x][goal_y])
  scanp();
  else
  {
    Stop();
    Serial.print("s");
  }
}
