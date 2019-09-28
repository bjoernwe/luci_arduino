#include "Luci.h"


Luci::Luci() {
	pixels = Adafruit_NeoPixel(2*LEDS_N_INNER + 2*LEDS_N_OUTER, PIN_PIXELS, NEO_GRBW + NEO_KHZ800);
	setLEDsAll(0);
}


Luci::~Luci() {
}


void Luci::begin(bool intro) {
	pixels.begin();
	if(intro) {
		for(int i=0; i<LEDS_N_OUTER; i++) {
			setLEDsOuterRight(i, 5);
			setLEDsOuterLeft(i, 5);
			show();
			delay(100);
		}
	}
}


void Luci::setLEDsAll(int x, int r, int g, int b, int w) {
	setLEDsLeft(x, r, g, b, w);
	setLEDsRight(x, r, g, b, w);
}


void Luci::setLEDsLeft(int x, int r, int g, int b, int w) {
	setLEDsInnerLeft(-1, x, r, g, b, w);
	setLEDsOuterLeft(-1, x, r, g, b, w);
}


void Luci::setLEDsRight(int x, int r, int g, int b, int w) {
	setLEDsInnerRight(-1, x, r, g, b, w);
	setLEDsOuterRight(-1, x, r, g, b, w);
}


void Luci::setLEDsInner(int n, int x, int r, int g, int b, int w) {
	setLEDsInnerLeft(n, x, r, g, b, w);
	setLEDsInnerRight(n, x, r, g, b, w);
}


void Luci::setLEDsOuter(int n, int x, int r, int g, int b, int w) {
	setLEDsOuterLeft(n, x, r, g, b, w);
	setLEDsOuterRight(n, x, r, g, b, w);
}


void Luci::setLEDsInnerLeft(int n, int x, int r, int g, int b, int w) {
	if(x >= 0) {
		r = x;
		g = x;
		b = x;
		w = x;
	}
	if(r >= 0) {
		if(n >= 0) {
			leds_inner_left[n][0] = r;
		} else {
			for(int i=0; i<LEDS_N_INNER; i++) {
				leds_inner_left[i][0] = r;
			}
		}
	}
	if(g >= 0) {
		if(n >= 0) {
			leds_inner_left[n][1] = g;
		} else {
			for(int i=0; i<LEDS_N_INNER; i++) {
				leds_inner_left[i][1] = g;
			}
		}
	}
	if(b >= 0) {
		if(n >= 0) {
			leds_inner_left[n][2] = b;
		} else {
			for(int i=0; i<LEDS_N_INNER; i++) {
				leds_inner_left[i][2] = b;
			}
		}
	}
	if(w >= 0) {
		if(n >= 0) {
			leds_inner_left[n][3] = w;
		} else {
			for(int i=0; i<LEDS_N_INNER; i++) {
				leds_inner_left[i][3] = w;
			}
		}
	}
}


void Luci::setLEDsInnerRight(int n, int x, int r, int g, int b, int w) {
	if(x >= 0) {
		r = x;
		g = x;
		b = x;
		w = x;
	}
	if(r >= 0) {
		if(n >= 0) {
			leds_inner_right[n][0] = r;
		} else {
			for(int i=0; i<LEDS_N_INNER; i++) {
				leds_inner_right[i][0] = r;
			}
		}
	}
	if(g >= 0) {
		if(n >= 0) {
			leds_inner_right[n][1] = g;
		} else {
			for(int i=0; i<LEDS_N_INNER; i++) {
				leds_inner_right[i][1] = g;
			}
		}
	}
	if(b >= 0) {
		if(n >= 0) {
			leds_inner_right[n][2] = b;
		} else {
			for(int i=0; i<LEDS_N_INNER; i++) {
				leds_inner_right[i][2] = b;
			}
		}
	}
	if(w >= 0) {
		if(n >= 0) {
			leds_inner_right[n][3] = w;
		} else {
			for(int i=0; i<LEDS_N_INNER; i++) {
				leds_inner_right[i][3] = w;
			}
		}
	}
}


void Luci::setLEDsOuterLeft(int n, int x, int r, int g, int b, int w) {
	if(x >= 0) {
		r = x;
		g = x;
		b = x;
		w = x;
	}
	if(r >= 0) {
		if(n >= 0) {
			leds_outer_left[n][0] = r;
		} else {
			for(int i=0; i<LEDS_N_OUTER; i++) {
				leds_outer_left[i][0] = r;
			}
		}
	}
	if(g >= 0) {
		if(n >= 0) {
			leds_outer_left[n][1] = g;
		} else {
			for(int i=0; i<LEDS_N_OUTER; i++) {
				leds_outer_left[i][1] = g;
			}
		}
	}
	if(b >= 0) {
		if(n >= 0) {
			leds_outer_left[n][2] = b;
		} else {
			for(int i=0; i<LEDS_N_OUTER; i++) {
				leds_outer_left[i][2] = b;
			}
		}
	}
	if(w >= 0) {
		if(n >= 0) {
			leds_outer_left[n][3] = w;
		} else {
			for(int i=0; i<LEDS_N_OUTER; i++) {
				leds_outer_left[i][3] = w;
			}
		}
	}
}


void Luci::setLEDsOuterRight(int n, int x, int r, int g, int b, int w) {
	if(x >= 0) {
		r = x;
		g = x;
		b = x;
		w = x;
	}
	if(r >= 0) {
		if(n >= 0) {
			leds_outer_right[n][0] = r;
		} else {
			for(int i=0; i<LEDS_N_OUTER; i++) {
				leds_outer_right[i][0] = r;
			}
		}
	}
	if(g >= 0) {
		if(n >= 0) {
			leds_outer_right[n][1] = g;
		} else {
			for(int i=0; i<LEDS_N_OUTER; i++) {
				leds_outer_right[i][1] = g;
			}
		}
	}
	if(b >= 0) {
		if(n >= 0) {
			leds_outer_right[n][2] = b;
		} else {
			for(int i=0; i<LEDS_N_OUTER; i++) {
				leds_outer_right[i][2] = b;
			}
		}
	}
	if(w >= 0) {
		if(n >= 0) {
			leds_outer_right[n][3] = w;
		} else {
			for(int i=0; i<LEDS_N_OUTER; i++) {
				leds_outer_right[i][3] = w;
			}
		}
	}
}


void Luci::show() {
	for(int i=0; i>LEDS_N_INNER; i++) {
		pixels.setPixelColor(LEDS_N_OUTER+i, pixels.Color(leds_inner_left[i][0], leds_inner_left[i][1], leds_inner_left[i][2], leds_inner_left[i][3]));
	}
	for(int i=0; i<LEDS_N_INNER; i++) {
		pixels.setPixelColor(2*LEDS_N_OUTER+LEDS_N_INNER+i, pixels.Color(leds_inner_right[i][0], leds_inner_right[i][1], leds_inner_right[i][2], leds_inner_right[i][3]));
	}
	for(int i=0; i<LEDS_N_OUTER; i++) {
		pixels.setPixelColor(i, pixels.Color(leds_outer_left[i][0], leds_outer_left[i][1], leds_outer_left[i][2], leds_outer_left[i][3]));
	}
	for(int i=0; i<LEDS_N_OUTER; i++) {
		pixels.setPixelColor(LEDS_N_OUTER+LEDS_N_INNER+i, pixels.Color(leds_outer_right[i][0], leds_outer_right[i][1], leds_outer_right[i][2], leds_outer_right[i][3]));
	}
        //for(int i=0; i<2*LEDS_N_INNER+2*LEDS_N_OUTER; i++) {
        //  pixels.setPixelColor(i, pixels.Color(255, 0, 0, 127));
        //}
	pixels.show();
}

