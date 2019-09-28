#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "Luci.h"


unsigned int brightness = 5;
unsigned int brightness_r = -1;
unsigned int brightness_g = -1;
unsigned int brightness_b = -1;
unsigned int brightness_w = -1;
unsigned int darkness = 0;
unsigned int darkness_r = -1;
unsigned int darkness_g = -1;
unsigned int darkness_b = -1;
unsigned int darkness_w = -1;
unsigned int hz = 15;
double dutyCycle = .5;
bool phaseShift = true;

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
		luci.setLEDsLeft(brightness, brightness_r, brightness_g, brightness_b, brightness_w);
		if(phaseShift) {
			luci.setLEDsRight(darkness, darkness_r, darkness_g, darkness_b, darkness_w);
		} else {
			luci.setLEDsRight(brightness, brightness_r, brightness_g, brightness_b, brightness_w);
		}
		break;
	}
	case 1: {
		digitalWrite(LED_BUILTIN, LOW);
		luci.setLEDsLeft(darkness, darkness_r, darkness_g, darkness_b, darkness_w);
		if(phaseShift) {
			luci.setLEDsRight(brightness, brightness_r, brightness_g, brightness_b, brightness_w);
		} else {
			luci.setLEDsRight(darkness, darkness_r, darkness_g, darkness_b, darkness_w);
		}
		break;
	}
	default: {
		luci.setLEDsLeft(darkness, darkness_r, darkness_g, darkness_b, darkness_w);
		luci.setLEDsRight(darkness, darkness_r, darkness_g, darkness_b, darkness_w);
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
				brightness_r = -1;
				brightness_g = -1;
				brightness_b = -1;
				brightness_w = -1;
				Serial.print("Brightness (on): ");
				Serial.println(brightness);
				break;
			}
			case 'b': {
				darkness = Serial.parseInt();
				darkness = constrain(darkness, 0, 255);
				darkness_r = -1;
				darkness_g = -1;
				darkness_b = -1;
				darkness_w = -1;
				Serial.print("Brightness (off): ");
				Serial.println(darkness);
				break;
			}
			case 'C': {
				Serial.setTimeout(100);
				brightness_r = Serial.parseInt();
				brightness_g = Serial.parseInt();
				brightness_b = Serial.parseInt();
				brightness_w = Serial.parseInt();
				brightness_r = constrain(brightness_r, 0, 255);
				brightness_g = constrain(brightness_g, 0, 255);
				brightness_b = constrain(brightness_b, 0, 255);
				brightness_w = constrain(brightness_w, 0, 255);
				brightness = -1;
				Serial.print("Color (on): (");
				Serial.print(brightness_r);
				Serial.print(", ");
				Serial.print(brightness_g);
				Serial.print(", ");
				Serial.print(brightness_b);
				Serial.print(", ");
				Serial.print(brightness_w);
				Serial.println(")");
				break;
			}
			case 'c': {
				Serial.setTimeout(100);
				darkness_r = Serial.parseInt();
				darkness_g = Serial.parseInt();
				darkness_b = Serial.parseInt();
				darkness_w = Serial.parseInt();
				darkness_r = constrain(darkness_r, 0, 255);
				darkness_g = constrain(darkness_g, 0, 255);
				darkness_b = constrain(darkness_b, 0, 255);
				darkness_w = constrain(darkness_w, 0, 255);
				darkness = -1;
				Serial.print("Color (off): (");
				Serial.print(darkness_r);
				Serial.print(", ");
				Serial.print(darkness_g);
				Serial.print(", ");
				Serial.print(darkness_b);
				Serial.print(", ");
				Serial.print(darkness_w);
				Serial.println(")");
				break;
			}
			case 'D': {
				unsigned int c = Serial.parseInt();
				c = constrain(c, 1, 100);
				dutyCycle = c / 100.;
				updateMillisToWait();
				Serial.print("DutyCycle: ");
				Serial.println(dutyCycle);
				break;
			}
			case 'H': {
				hz = Serial.parseInt();
				hz = constrain(hz, 1, 100);
				updateMillisToWait();
				Serial.print("Hz: ");
				Serial.println(hz);
				break;
			}
			case 'X': {
				bool x = Serial.parseInt();
				phaseShift = x;
				Serial.print("Phase Shift: ");
				Serial.println(phaseShift);
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

