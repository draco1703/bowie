#include <movlibemu.h>
#include <usenslibemu.h>
#include <Arduino.h>

/* 0=open space;1=wall;2=exit */
char* maze = "1121111011110111101111011";
int mazeWidth = 5; /* how many characters makes up one row of maze */

Usens eye();
Mov leg();
  
void setup() {
	Serial.begin(9600);
	Serial.println(maze);
	Serial.println(maze[3]);
	eye.isBlocked(10);
}

void loop() {

}
