#pragma once
#include "header.h"

class WaterTerrain : public BaseTerrain {
public:
	WaterTerrain() {};
	WaterTerrain(BaseTerrain& terrain);

	virtual string GetSubsoil();
	virtual string GetWaterColor();
	
	virtual void DrawOn(Svg* scgImage);
};