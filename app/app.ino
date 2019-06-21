#include <usenslib.h>
#include <movlib.h>

Usens eyeRight(12, 13);
Usens eyeFront(2, 3);

Mov wheels(4, 5, 6, 7, 8, 9);

void setup() {
	Serial.begin(9600);
}

void loop() {
	if(eyeRight.isBlocked(20) == false){
		wheels.turnRight(128);
		delay(250);
		wheels.stop();
	} else if(eyeFront.isBlocked(20) == false) {
		wheels.advance(128);
		delay(250);
		wheels.stop();
	} else {
		wheels.turnLeft(128);
		delay(250);
		wheels.stop();
	}
}
