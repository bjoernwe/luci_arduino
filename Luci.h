#ifndef LUCI_H_
#define LUCI_H_

#include <Adafruit_NeoPixel.h>

#define PIN_INNER 6
#define PIN_OUTER 7

#define LEDS_N_INNER  7
#define LEDS_N_OUTER 12


class Luci {
public:
	unsigned int leds_left_inner[LEDS_N_INNER][3];
	unsigned int leds_left_outer[LEDS_N_OUTER][4];
	unsigned int leds_right_inner[LEDS_N_INNER][3];
	unsigned int leds_right_outer[LEDS_N_OUTER][4];
	Adafruit_NeoPixel pixels_inner;
	Adafruit_NeoPixel pixels_outer;
public:
	Luci();
	virtual ~Luci();
	void setLEDsAll(int x, int r=-1, int g=-1, int b=-1, int w=-1);
	void setLEDsLeft(int x, int r=-1, int g=-1, int b=-1, int w=-1);
	void setLEDsRight(int x, int r=-1, int g=-1, int b=-1, int w=-1);
	void setLEDsInner(int x, int r=-1, int g=-1, int b=-1);
	void setLEDsOuter(int x, int r=-1, int g=-1, int b=-1, int w=-1);
	void setLEDsInnerLeft(int x, int r=-1, int g=-1, int b=-1);
	void setLEDsInnerRight(int x, int r=-1, int g=-1, int b=-1);
	void setLEDsOuterLeft(int x, int r=-1, int g=-1, int b=-1, int w=-1);
	void setLEDsOuterRight(int x, int r=-1, int g=-1, int b=-1, int w=-1);
protected:
private:
};


#endif /* LUCI_H_ */
