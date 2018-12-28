#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "Luci.h"


Luci luci = Luci();


void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(9600);
	luci.begin();
	for(int i=0; i<=255; i++) {
		luci.setLEDsAll(-1, 0, 0, 0, i);
		luci.show();
		delay(20);
	}
}


void loop() {
	digitalWrite(LED_BUILTIN, HIGH);
	luci.setLEDsAll(5);
	luci.show();
	Serial.println(HIGH);
	delay(500);

	digitalWrite(LED_BUILTIN, LOW);
	luci.setLEDsAll(0);
	luci.show();
	Serial.println(LOW);
	delay(500);
}
