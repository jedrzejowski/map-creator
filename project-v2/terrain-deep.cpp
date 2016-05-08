#include "header.h"

DeepTerrain::DeepTerrain(WaterTerrain& base){
	InsertConstructor(base);
}

string DeepTerrain::GetWaterColor() {
	return "rgba(124,183,243,0.75)";
}
