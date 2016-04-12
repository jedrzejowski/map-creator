#pragma once
#include <string>
using namespace std;

class Terrain {
public:
	Terrain *Next;
	string Texture;
	string Type;
	int Height, X, Y;
	bool Water;
	void setHeight(int seaLvl);

	void drawInSvg(Svg &svg);

	static Terrain* Create(stringstream&data);

	virtual string getSvgColor();
};

class SandTerrain: public Terrain {
	virtual string getSvgColor() override;
};

class MountainTerrain : public Terrain {
	virtual string getSvgColor() override;
};

class ForestTerrain : public Terrain {
	virtual string getSvgColor() override;
};