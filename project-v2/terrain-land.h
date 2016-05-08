#pragma once
#include "header.h"

class LandTerrain : public BaseTerrain {
public:
	LandTerrain(BaseTerrain& terrain);

	virtual string GetSubsoil() { return "green"; }

	//virtual void DrawOn(Svg* scgImage);
};