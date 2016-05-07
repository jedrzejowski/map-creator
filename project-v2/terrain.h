#pragma once
#include "header.h"

class BaseTerrain {
	int X, Y, Z;

public:
	BaseTerrain();
	BaseTerrain(int x, int y);
	BaseTerrain(int x, int y, int z);

	int GetX();
	int GetY();
	int GetZ();

	void SetX(int val);
	void SetY(int val);
	void SetZ(int val);

	virtual string GetSubsoil();
	
	
	virtual void DrawOn(Svg* svgImage);

};
