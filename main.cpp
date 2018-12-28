#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "Luci.h"


unsigned int brightness = 5;
unsigned int hz = 15;
double dutyCycle = .5;

// do not edit directly
unsigned long millisLast;
unsigned long millisNext;
unsigned int millisToWait;
unsigned int millisDutyCycle;

Luci luci = Luci();


static void updateMillisToWait();


void setup() {

	// init
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(9600);
	while(!Serial) {
	    ; // wait for serial port to connect. Needed for native USB
	}
	luci.begin();

	// fade white light
	if(false) {
		for(int i=0; i<=255; i++) {
			luci.setLEDsAll(-1, 0, 0, 0, i);
			luci.show();
			delay(20);
		}
	}

	//
	updateMillisToWait();
	millisLast = millis();
	millisNext = millisLast + millisToWait;
}


void loop() {

	unsigned long currentTime = millis();
	if(currentTime >= millisNext) {
		millisLast = millisNext;
		millisNext = millisLast + millisToWait;
	}
	unsigned int millisPast = currentTime-millisLast;
	unsigned int cycle = millisPast / millisDutyCycle;

	switch(cycle) {
	case 0: {
		digitalWrite(LED_BUILTIN, HIGH);
		luci.setLEDsLeft(brightness);
		luci.setLEDsRight(0);
		break;
	}
	case 1: {
		digitalWrite(LED_BUILTIN, LOW);
		luci.setLEDsLeft(0);
		luci.setLEDsRight(brightness);
		break;
	}
	default: {
		luci.setLEDsLeft(0);
		luci.setLEDsRight(0);
	}
	}
	luci.show();
}


/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
	while(Serial.available()) {
		int c = Serial.read();
		switch(c) {
			case '\n': break;
			case 'B': {
				brightness = Serial.parseInt();
				brightness = constrain(brightness, 0, 255);
				Serial.print("Brightness: ");
				Serial.println(brightness);
				break;
			}
			case 'D': {
				unsigned int c = Serial.parseInt();
				c = constrain(c, 1, 100);
				dutyCycle = c / 100.;
				Serial.print("DutyCycle: ");
				Serial.println(dutyCycle);
				updateMillisToWait();
				break;
			}
			case 'H': {
				hz = Serial.parseInt();
				hz = constrain(hz, 1, 100);
				Serial.print("Hz: ");
				Serial.println(hz);
				updateMillisToWait();
				break;
			}
			default: Serial.println(c);
		}
	}
}


static void updateMillisToWait() {
	millisToWait = 1000. / hz;
	millisDutyCycle = millisToWait * dutyCycle;
}

