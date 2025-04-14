#include "runner.h"


void setup() {
	// set the serial link to 115200 bps
	Serial.begin(115200);
}

void loop() {
	// Run the runner as the main loop
	Runner runner;
	runner.run();
}
