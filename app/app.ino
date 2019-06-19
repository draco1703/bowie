#include <movlibemu.h>
#include <usenslibemu.h>
#include <Arduino.h>
#include <string.h>

char* maze = "1121111011110111101111011"; /* 0=open space;1=wall;2=exit */
int mazeWidth = 5; /* how many characters makes up one row of maze */

void setup() {
	Serial.begin(9600);
	
	Usens centerEye;
	Mov legs;
	printMaze();
}

/* prints maze in serial monitor */
void printMaze(){
	for (int i = 0; i < strlen(maze); i++){
		Serial.print(maze[i]);

		if(i > 0 && i % mazeWidth == 0){
			Serial.print("\n");
		}
	}
}

void loop() {

}
