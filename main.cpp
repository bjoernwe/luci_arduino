#include <Arduino.h>

#include "Luci.h"


void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
	digitalWrite(LED_BUILTIN, HIGH);
	delay(500);
	digitalWrite(LED_BUILTIN, LOW);
	delay(500);
}
