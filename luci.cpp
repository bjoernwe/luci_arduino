#include "luci.h"


luci::luci() {
	this->pixels_inner = Adafruit_NeoPixel(2*LEDS_INNER, 6, NEO_BGR  + NEO_KHZ800);
	this->pixels_outer = Adafruit_NeoPixel(2*LEDS_OUTER, 7, NEO_BGR  + NEO_KHZ800);
	for(int i=0; i<2*LEDS_INNER; i++) {
		//
	}
}


luci::~luci() {
}

