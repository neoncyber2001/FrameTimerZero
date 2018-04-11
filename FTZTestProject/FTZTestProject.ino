/*
 Name:		FTZTestProject.ino
 Created:	4/10/2018 8:56:23 PM
 Author:	djneo
*/
#include <FrameTimerZero.h>
// the setup function runs once when you press reset or power the board
uint8_t ledLevel = 0;
FrameTimerZero FTZ = FrameTimerZero(30);
void setup() {
	FTZ.setMainFrame(doLed);
}

// the loop function runs over and over again until power down or reset
void loop() {
  
}

void doLed(uint32_t frame) {
	double out = (0.5 * cos((2 * PI * frame) / 30)) + 0.5;
	ledLevel = ()
}