#pragma once
#include "header.h"

class WaterTerrain : public BaseTerrain {
public:
	WaterTerrain() {};
	WaterTerrain(BaseTerrain& terrain);

	virtual Color GetBaseColor();
	virtual Color GetWaterColor();
	
	virtual void DrawOn(Svg* scgImage);
};