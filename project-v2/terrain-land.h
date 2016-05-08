#pragma once
#include "header.h"

class LandTerrain : public BaseTerrain {
public:
	LandTerrain() { };
	LandTerrain(BaseTerrain& terrain);

	virtual Color GetBaseColor();

	//virtual void DrawOn(Svg* scgImage);
};