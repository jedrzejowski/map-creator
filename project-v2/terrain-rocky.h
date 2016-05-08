#pragma once
#include "header.h"

class RockyTerrain : public LandTerrain {
public:
	RockyTerrain() { };
	RockyTerrain(LandTerrain& terrain);

	virtual Color GetBaseColor();
};