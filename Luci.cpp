#include "Luci.h"


Luci::Luci() {
	this->pixels_inner = Adafruit_NeoPixel(2*LEDS_N_INNER, 6, NEO_BGR  + NEO_KHZ800);
	this->pixels_outer = Adafruit_NeoPixel(2*LEDS_N_OUTER, 7, NEO_BGRW + NEO_KHZ800);
	for(int i=0; i<LEDS_N_INNER; i++) {
		this->leds_left_inner[i][0]  = 0;
		this->leds_left_inner[i][1]  = 0;
		this->leds_left_inner[i][2]  = 0;
		this->leds_right_inner[i][0] = 0;
		this->leds_right_inner[i][1] = 0;
		this->leds_right_inner[i][2] = 0;
	}
	for(int i=0; i<LEDS_N_OUTER; i++) {
		this->leds_left_outer[i][0]  = 0;
		this->leds_left_outer[i][1]  = 0;
		this->leds_left_outer[i][2]  = 0;
		this->leds_left_outer[i][3]  = 0;
		this->leds_right_outer[i][0] = 0;
		this->leds_right_outer[i][1] = 0;
		this->leds_right_outer[i][2] = 0;
		this->leds_right_outer[i][3] = 0;
	}
}


Luci::~Luci() {
}


void Luci::setLEDsAll(int x, int r, int g, int b, int w) {
	setLEDsLeft(x, r, g, b, w);
	setLEDsRight(x, r, g, b, w);
}


void Luci::setLEDsLeft(int x, int r, int g, int b, int w) {

}


void Luci::setLEDsRight(int x, int r, int g, int b, int w) {

}
