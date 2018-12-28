#include "Luci.h"


Luci::Luci() {
	//pixels_inner = Adafruit_NeoPixel(2*LEDS_N_INNER, PIN_INNER, NEO_GRB  + NEO_KHZ800);
	pixels_outer = Adafruit_NeoPixel(2*LEDS_N_OUTER, PIN_OUTER, NEO_GRBW + NEO_KHZ800);
	setLEDsAll(0);
}


Luci::~Luci() {
}


void Luci::begin(bool intro) {
	//pixels_inner.begin();
	pixels_outer.begin();
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
	//setLEDsInnerLeft(-1, x, r, g, b);
	setLEDsOuterLeft(-1, x, r, g, b, w);
}


void Luci::setLEDsRight(int x, int r, int g, int b, int w) {
	//setLEDsInnerRight(-1, x, r, g, b);
	setLEDsOuterRight(-1, x, r, g, b, w);
}


//void Luci::setLEDsInner(int n, int x, int r, int g, int b) {
//	setLEDsInnerLeft(n, x, r, g, b);
//	setLEDsInnerRight(n, x, r, g, b);
//}


void Luci::setLEDsOuter(int n, int x, int r, int g, int b, int w) {
	setLEDsOuterLeft(n, x, r, g, b, w);
	setLEDsOuterRight(n, x, r, g, b, w);
}


//void Luci::setLEDsInnerLeft(int n, int x, int r, int g, int b) {
//	if(x >= 0) {
//		r = x;
//		g = x;
//		b = x;
//	}
//	if(r >= 0) {
//		if(n >= 0) {
//			leds_inner_left[n][0] = r;
//		} else {
//			for(int i=0; i<LEDS_N_INNER; i++) {
//				leds_inner_left[i][0] = r;
//			}
//		}
//	}
//	if(g >= 0) {
//		if(n >= 0) {
//			leds_inner_left[n][1] = g;
//		} else {
//			for(int i=0; i<LEDS_N_INNER; i++) {
//				leds_inner_left[i][1] = g;
//			}
//		}
//	}
//	if(b >= 0) {
//		if(n >= 0) {
//			leds_inner_left[n][2] = b;
//		} else {
//			for(int i=0; i<LEDS_N_INNER; i++) {
//				leds_inner_left[i][2] = b;
//			}
//		}
//	}
//}


//void Luci::setLEDsInnerRight(int n, int x, int r, int g, int b) {
//	if(x >= 0) {
//		r = x;
//		g = x;
//		b = x;
//	}
//	if(r >= 0) {
//		if(n >= 0) {
//			leds_inner_right[n][0] = r;
//		} else {
//			for(int i=0; i<LEDS_N_INNER; i++) {
//				leds_inner_right[i][0] = r;
//			}
//		}
//	}
//	if(g >= 0) {
//		if(n >= 0) {
//			leds_inner_right[n][1] = g;
//		} else {
//			for(int i=0; i<LEDS_N_INNER; i++) {
//				leds_inner_right[i][1] = g;
//			}
//		}
//	}
//	if(b >= 0) {
//		if(n >= 0) {
//			leds_inner_right[n][2] = b;
//		} else {
//			for(int i=0; i<LEDS_N_INNER; i++) {
//				leds_inner_right[i][2] = b;
//			}
//		}
//	}
//}


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
//	for(int i=0; i<LEDS_N_INNER; i++) {
//		pixels_inner.setPixelColor(i, pixels_inner.Color(leds_inner_right[i][0], leds_inner_right[i][1], leds_inner_right[i][2]));
//	}
//	for(int i=LEDS_N_INNER-1; i>=0; i--) {
//		pixels_inner.setPixelColor(i, pixels_inner.Color(leds_inner_left[i][0], leds_inner_left[i][1], leds_inner_left[i][2]));
//	}
	for(int i=0; i<LEDS_N_OUTER; i++) {
		pixels_outer.setPixelColor(i, pixels_outer.Color(leds_outer_right[i][0], leds_outer_right[i][1], leds_outer_right[i][2], leds_outer_right[i][3]));
	}
	for(int i=0; i<LEDS_N_OUTER; i++) {
		pixels_outer.setPixelColor(2*LEDS_N_OUTER-i-1, pixels_outer.Color(leds_outer_left[i][0], leds_outer_left[i][1], leds_outer_left[i][2], leds_outer_left[i][3]));
	}
	//pixels_inner.show();
	pixels_outer.show();
}

