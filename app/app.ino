#include <movlibemu.h>
#include <usenslibemu.h>
#include <Arduino.h>
#include <string.h>

/* init sensor emulators */
Usens centerEye;
Mov legs;

/* 0=open space;1=wall;2=exit */
char* maze = "1121111011110111101111011";
const int width = 5;

/* inital pos of robot */
int pos = 21;

/* needed values for using pledge algo for maze solving */
int turnCount = 0;

void setup() {
	Serial.begin(9600);

	printMaze();
}

/* prints maze in serial monitor */
void printMaze(){
	for (int i = 0; i < strlen(maze); i++){
	  if(i > 0 && i % width == 0){
      Serial.print("\n");
	  }
	  Serial.print(maze[i]);
	}
}

void loop() {
}
