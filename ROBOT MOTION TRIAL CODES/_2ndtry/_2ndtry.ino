//WAVEFRONT ALGORITHM TEST IN SERIAL MONITOR WHEN MATRIX IS FILLED ON ITS OWN
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
  digitalWrite(2, HIGH);
  digitalWrite(3,LOW );
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7,LOW );
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}

void right()
{
  digitalWrite(2, LOW);
  digitalWrite(3,HIGH );
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7,HIGH );
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}

void up()
{
  digitalWrite(2, HIGH);
  digitalWrite(3,LOW );
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7,LOW );
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}

void down()
{
  digitalWrite(2, LOW);
  digitalWrite(3,HIGH);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
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
//int propagate_wavefront(int robot_x, int robot_y, int goal_x, int goal_y);
//void unpropagate(int robot_x, int robot_y);
//int min_surrounding_node_value(int x, int y);
//void clear_map(void);


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
  delay(500);
  up();
  Serial.println("u");
  delay(900);
  right();
  delay(500);
}
if(e==Map[robot_x][robot_y+1])
{
 robot_y=robot_y+1;
  right();
  Serial.println("r");
  delay(500);
  up();
  Serial.println("u");
  delay(900);
  left();
  delay(500);
}
if(e==Map[robot_x-1][robot_y])
{
  robot_x=robot_x-1;
  up();
  Serial.println("u");
  delay(900);
}
if(e==Map[robot_x+1][robot_y])
{
  robot_x=robot_x+1;
  down();
  Serial.println("d");
  delay(900);
}
}

void setup() {
Serial.begin(9600);
 pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  digitalWrite(14,HIGH);
  digitalWrite(15,HIGH);
  digitalWrite(16,HIGH);
  digitalWrite(17,HIGH);
  unpropagate(robot_x, robot_y);
  propagate_wavefront(robot_x,robot_y,goal_x,goal_y);
 for(int i=0;i<6;i++)
 {
  for(int j=0;j<6;j++)
  {
    if(Map[i][j]==nothing)
    propagate_wavefront(robot_x,robot_y,goal_x,goal_y);
  }
}
  for(int i=0;i<6;i++)
{
  for(int j=0;j<6;j++)
  {
     Serial.print(Map[i][j]);
     Serial.print(" ");
  }
  Serial.println();
}
  
//for(int i=0;i<6;i++)
//{
//  for(int j=0;j<6;j++)
//  {
//    if(Map[i][j]<min_val)
//    {
//      min_val=Map[i][j];
//    }
//  }
//}
//Serial.print(min_val);
}





void loop() {
//  propagate_wavefront(robot_x,robot_y,goal_x,goal_y);
//  for(int i=0;i<6;i++)
//{
//  for(int j=0;j<6;j++)
//  {
//     Serial.print(Map[i][j]);
//     Serial.print(" ");
//  }
//  Serial.println();
//}
 if(Map[robot_x][robot_y]!=Map[goal_x][goal_y])
  scanp();
  else
  {
    Stop();
    Serial.print("s");
  }
}
