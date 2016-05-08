#include "header.h"

RockyTerrain::RockyTerrain(LandTerrain& base) {
	InsertConstructor(base);
}

Color RockyTerrain::GetBaseColor() {
	return Color(200,200,200);
}
