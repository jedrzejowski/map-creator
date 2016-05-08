#pragma once
#include "header.h"

class DeepTerrain : public WaterTerrain {
public:
	DeepTerrain(WaterTerrain& terrain);

	virtual string GetWaterColor();
};