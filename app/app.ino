#include <usenslib.h>
#include <movlib.h>

Usens eyeRight(12, 13);
Usens eyeFront(2, 3);

Mov wheels(4, 5, 6, 7, 8, 9);
int turnCount;
int heading;

void setup() {
	Serial.begin(9600);
	turnCount = 0;
	heading = 0;
}

void loop() {
	/* wall follower */
/* 	if(eyeRight.isBlocked(20) == false){
		wheels.turnRight(128);
		delay(250);
		wheels.stop();
	}
	
	if(eyeFront.isBlocked(20) == false) {
		wheels.advance(128);
		delay(500);
		wheels.stop();
	} else {
		wheels.turnLeft(128);
		delay(250);
		wheels.stop();
	}
 */
		if(heading == 360 || heading == -360){
			heading = 0;
		}
		
		if(turnCount == 0 && heading == 0 && eyeFront.isBlocked(20) == false){
			wheels.advance(128);
			delay(500);
			wheels.stop();
		} else {
			wallFollow();
		}
	}
}

void wallFollow(){
		if(eyeRight.isBlocked(20) == false){
			turnCount++;
			heading += 90;
			wheels.turnRight(128);
			delay(250);
			wheels.stop();
		}
		
		if(eyeFront.isBlocked(20) == false){
			wheels.advance(128);
			delay(500);
			wheels.stop();
		} else {
			turnCount--;
			heading -= 90;
			wheels.turnLeft(128);
			delay(250);
			wheels.stop();
		}
}
