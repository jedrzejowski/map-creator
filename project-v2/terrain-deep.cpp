#include "header.h"

DeepTerrain::DeepTerrain(WaterTerrain& base){
	InsertConstructor(base);
}

Color DeepTerrain::GetWaterColor() {
	return Color(124,183,243,0.75);
}
