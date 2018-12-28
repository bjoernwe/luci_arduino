#ifndef LUCI_H_
#define LUCI_H_

#include <Adafruit_NeoPixel.h>

//#define PIN_INNER 6
#define PIN_OUTER 7

//#define LEDS_N_INNER  7
#define LEDS_N_OUTER 12


class Luci {
public:
	//unsigned int leds_inner_left[LEDS_N_INNER][3];
	//unsigned int leds_inner_right[LEDS_N_INNER][3];
	unsigned int leds_outer_left[LEDS_N_OUTER][4];
	unsigned int leds_outer_right[LEDS_N_OUTER][4];
	//Adafruit_NeoPixel pixels_inner;
	Adafruit_NeoPixel pixels_outer;
public:
	Luci();
	virtual ~Luci();
	void begin(bool intro=true);
	void setLEDsAll(int x, int r=-1, int g=-1, int b=-1, int w=-1);
	void setLEDsLeft(int x, int r=-1, int g=-1, int b=-1, int w=-1);
	void setLEDsRight(int x, int r=-1, int g=-1, int b=-1, int w=-1);
	//void setLEDsInner(int n, int x, int r=-1, int g=-1, int b=-1);
	void setLEDsOuter(int n, int x, int r=-1, int g=-1, int b=-1, int w=-1);
	//void setLEDsInnerLeft(int n, int x, int r=-1, int g=-1, int b=-1);
	//void setLEDsInnerRight(int n, int x, int r=-1, int g=-1, int b=-1);
	void setLEDsOuterLeft(int n, int x, int r=-1, int g=-1, int b=-1, int w=-1);
	void setLEDsOuterRight(int n, int x, int r=-1, int g=-1, int b=-1, int w=-1);
	void show();
protected:
private:
};


#endif /* LUCI_H_ */
