#include <movlibemu.h>
#include <usenslibemu.h>
#include <Arduino.h>
#include <string.h>

/* inital pos of robot */
int pos;

/* stuff for pledge algo */
int turnCount;
int heading;

/* counts amount of moves it machine takes */
int moveCounter;

/* init sensor emulators */
Usens eyes;
Mov legs;

/* 
	DEMO MAZES

	0 = nothing
	1 = wall
	E = exit 
*/

/* simple maze */
//char maze[] = "11E111001110111100111101111111";
//const int width = 5;
//pos = 22;

/* big maze */
//char maze[] = "1E1111111111111111111100000100000000000001101110111010101110101101000001010100010101111010111011111111101100010001010000010001111011101110111110101101000100000100000101101111101111111011101100010001000000000101101111101010111010101100000000010001010101111010101010111011101101010101010001010101101010101011101010101100010101010101010101111010111110111010101100010100010001010101101110111010101110101100010000000100010001111111111111111111111";
//const int width = 21;
//pos = 402;
//legs.turnLeft(compass);

/* medium maze */
//char maze[] = "1011111111111111111111010001000101000001011010101011101011101011010101000100010000011011101011111110111011000000000000000100011111111111111111111E1";
//const int width = 21;
//pos = 1;
//legs.turnLeft(compass);
//legs.turnLeft(compass);

/*G-shaped maze to demonstrate Pledge*/
char maze[] = "000000000000000111111000000100000000000101111000000100001000000111111000E00000000000";
const int width = 12;

/* forward, backwards, left, right */
int compass[] = {-width, width, -1, 1};

void setup() {
	Serial.begin(9600);
	
	pos = 34;
	legs.turnLeft(compass);

	turnCount = 0;
	moveCounter = 0;
}
/* prints maze in serial monitor */
void printMaze(){
	for (int i = 0; i < strlen(maze); i++){
		if(i > 0 && i % width == 0){
			Serial.print("\n");
		}
		
		if(i == pos) {
			Serial.print("@");
		} else if(maze[i] == '1'){
			Serial.print("▓");
			//Serial.print("#");
		} else if (maze[i] == '0'){
			Serial.print(" ");
		} else {
			Serial.print("E");
		}
	}

	Serial.println();
	Serial.println();
}

void loop() {

/*
	Serial.print("position: ");
	Serial.println(pos);
	Serial.print("turn count: ");
	Serial.println(turnCount);
	Serial.print("facing: ");
	Serial.println(compass[0]);
*/
	//printMaze();

	if(maze[pos] == 'E'){
		Serial.print("Escaped in ");
		Serial.print(moveCounter);
		Serial.println(" moves!");

		printMaze();
		Serial.end();
	} else {
		moveCounter++;
		
		/* ! might be unneeded ! */
		/* reset heading on full rotation */
		if(heading == 360 || heading == -360){
			heading = 0;
		}

		if(turnCount == 0 && heading == 0 && eyes.isBlocked(maze, pos, compass[0]) == false){
			legs.advance(pos, compass);
		} else {
			wallFollow();
		}
	}
}

void wallFollow(){
		if(eyes.isBlocked(maze, pos, compass[3]) == false){
			turnCount++;
			heading += 90;
			legs.turnRight(compass);
		}
		
		if(eyes.isBlocked(maze, pos, compass[0]) == false){
			legs.advance(pos, compass);
		} else {
			turnCount--;
			heading -= 90;
			legs.turnLeft(compass);
		}
}
