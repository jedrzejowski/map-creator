#include "header.h"

WaterTerrain::WaterTerrain(BaseTerrain& base) {
	SetX(base.GetX());
	SetY(base.GetY());
	SetZ(base.GetZ());
}

string WaterTerrain::GetSubsoil() {
	return "blue";
}