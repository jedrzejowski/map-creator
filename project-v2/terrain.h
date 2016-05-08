#pragma once
#include "header.h"

class BaseTerrain {
	int X, Y, Z;

protected:
	void InsertConstructor(BaseTerrain& base);

	template <typename T>
	bool is(T className);

public:
	BaseTerrain();
	BaseTerrain(int x, int y, int z);

	void Init();

	int GetX();
	int GetY();
	int GetZ();

	void SetX(int val);
	void SetY(int val);
	void SetZ(int val);

	virtual string GetSubsoil();
	
	
	virtual void DrawOn(Svg* svgImage);

};
