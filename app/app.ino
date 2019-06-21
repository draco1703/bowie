#include <movlibemu.h>
#include <usenslibemu.h>
#include <Arduino.h>
#include <string.h>

/* 0=open space;1=wall;2=exit */
char maze[] = "11111112111001110101100011101111111";
const int width = 5;

/* forward, backwards, left, right */
int compass[] = {-width, width, -1, 1};

/* inital pos of robot */
int pos;
int turnCount;

/* init sensor emulators */
Usens eyes;
Mov legs;

void setup() {
	Serial.begin(9600);
	pos = 27;
	turnCount = 0;
}
/* prints maze in serial monitor */
void printMaze(){
	for (int i = 0; i < strlen(maze); i++){
		if(i > 0 && i % width == 0){
			Serial.print("\n");
		}
		i==pos ? Serial.print("@") : Serial.print(maze[i]);
	}
	Serial.println();
	Serial.println();
}

void loop() {
	printMaze();

	/* check if current pos is exit (2) */
	if(maze[pos] == '2'){
		Serial.println("Success!");
		Serial.end();
	} else {
		Serial.print("tc: ");
		Serial.println(turnCount);

		/* if turnCount is not zero then the robot is wallfollowing */
		/* the robot will start wallfollowing if the wall infront is blocked */
		if(turnCount != 0 || eyes.isBlocked(maze, pos, compass[0])){
			wallFollow();
		} else {
			legs.advance(pos, compass);
		}
	}
}

void wallFollow(){
		if(eyes.isBlocked(maze, pos, compass[3]) == false){
			turnCount++;
			legs.turnRight(compass);
		}
		
		if(eyes.isBlocked(maze, pos, compass[0]) == false){
			legs.advance(pos, compass);
		} else {
			turnCount--;
			legs.turnLeft(compass);
		}
}