#include "Ellips.h"
#include <Novice.h>

void Ellips::Draw() {
	Novice::DrawEllipse(
		static_cast<int>(localCo_.screenFromOrigin(pos_).x),
		static_cast<int>(localCo_.screenFromOrigin(pos_).y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		angle_, color_, kFillModeSolid
	);
}