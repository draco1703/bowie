#include <usenslib.h>
#include <movlib.h>

/* XY */
int lab[5][5] = {
  {1,1,0,1,1},
  {1,0,0,1,1},
  {1,0,1,1,1},
  {1,0,0,1,1},
  {1,1,0,1,1}
};

Usens eyes(7, 8);
Mov wheels(1, 2, 3, 4, 5, 6);

void setup() {
  Serial.begin(9600);
}

void loop() {
  while(eyes.isBlocked(10) == false){
    wheels.advance(160); /* 0 - 255 */
  }
  
  wheels.turnLeft(100);
  
  if(eyes.isBlocked(10)){
    wheels.turnRight(100);
    wheels.turnRight(100);
  }
}
