#ifndef LUCI_H_
#define LUCI_H_

#include <Adafruit_NeoPixel.h>

#define LEDS_INNER  7
#define LEDS_OUTER 12


class luci {
public:
	unsigned int leds_left_inner[LEDS_INNER][3];
	unsigned int leds_left_outer[LEDS_OUTER][4];
	unsigned int leds_right_inner[LEDS_INNER][3];
	unsigned int leds_right_outer[LEDS_OUTER][4];
	Adafruit_NeoPixel pixels_inner;
	Adafruit_NeoPixel pixels_outer;
public:
	luci();
	virtual ~luci();
protected:
private:
};


#endif /* LUCI_H_ */
