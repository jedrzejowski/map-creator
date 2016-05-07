#pragma once
#include "header.h"

using namespace std;

class Map {
private:
	Map();
	vector<vector<BaseTerrain>> surface;

	Settings* mapSettings;
	Svg* outputImage;

public:
	static Map& GetInstance();
	void SetArgs(int argc, char* argv[]);

	void GenerateSurface();
	void DrawMap(string path);

	BaseTerrain& GetTerrain(int x, int y);
	void SetTerrain(int x, int y, BaseTerrain& terrain);

	//Settings
	int GetLength();
	int GetWidth();
	int GetMaxHeight();
	int GetMinHeight();
	int GetHeightDiff();
	
};