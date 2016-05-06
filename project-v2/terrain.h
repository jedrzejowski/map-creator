#pragma once
#include "header.h"

class BaseTerrain {
	int X, Y, Z;

public:
	BaseTerrain();
	BaseTerrain(int x, int y);
	BaseTerrain(int x, int y, int z);

	int getX();
	int getY();
	int getZ();

	void setX(int val);
	void setY(int val);
	void setZ(int val);
	//virtual void DrawOn();

};
