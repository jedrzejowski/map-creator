#pragma once
#include "header.h"

class SandTerrain : public LandTerrain {
public:
	SandTerrain() { };
	SandTerrain(LandTerrain& terrain);

	virtual Color GetBaseColor();
};