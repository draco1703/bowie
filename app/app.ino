#include <usenslib.h>
#include <movlib.h>

Usens eyes(12, 13);
Mov wheels(4, 5, 6, 7, 8, 9);

void setup() {
	Serial.begin(9600);
}

void loop() {
	if(eyes.isBlocked(5) == false){
		wheels.advance(128); /* 0 - 255 */
	} else {
		wheels.stop();
		delay(250);
		wheels.turnLeft(128);

		/* turn 180 degrees right if left wall is blocked */
		if(eyes.isBlocked(20)){
			wheels.turnRight(128);
			wheels.turnRight(128);
		}
	}
}
