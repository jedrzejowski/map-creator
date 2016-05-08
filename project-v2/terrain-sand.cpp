#include "header.h"

SandTerrain::SandTerrain(LandTerrain& base) {
	InsertConstructor(base);
}

Color SandTerrain::GetBaseColor() {
	return Color(255,200,0);
}
