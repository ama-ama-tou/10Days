#include "easing.h"
#define _USE_MATH_DEFINES
#include <math.h>

float easeInOutQuart(float t) {
	return t < 0.5 ? 8 * t * t * t * t : 1 -pow(-2 * t + 2, 4) / 2;
}
