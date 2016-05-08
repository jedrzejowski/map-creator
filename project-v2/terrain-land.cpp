#include "header.h"

LandTerrain::LandTerrain(BaseTerrain& base) {
	InsertConstructor(base);

	static float bleachLvl = Map::GetInstance().GetAmplitude() * 0.1;
	if (GetZ() < bleachLvl) {
		new SandTerrain(*this);
		delete this;
	}

	static float rockLvl = Map::GetInstance().GetAmplitude() * 0.7;
	if (GetZ() > rockLvl) {
		new RockyTerrain(*this);
		delete this;
	}
}

Color LandTerrain::GetBaseColor() {
	return Color(0, 200, 0);
}
