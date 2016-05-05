#pragma once
#include "header.h"

using namespace std;

class Map {
private:
	Settings mapSettings;
	Map();
	BaseTerrain** surface;

public:
	static Map& GetInstance();
	void SetArgs(int argc, char* argv[]);

	void GenerateSurface();


	BaseTerrain* getTerrain(int x, int y);

	//Settings
	int getLength();
	int getWidth();
	int getMaxHeight();
	int getMinHeight();
	int getHeightDiff();
	double getRoughness();
};