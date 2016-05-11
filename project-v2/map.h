#pragma once
#include "header.h"

class Map {
private:
	Map();

	vector<vector<Terrain::Base*>> surface;
	Svg::SvgImage* outputImage;

	int LowestPoint;
public:
	Settings* mapSettings;
	static Map& GetInstance();
	void SetArgs(int argc, char* argv[]);

	void GenerateSurface();
	void DrawMap(string path);

	Terrain::Base* GetTerrain(int x, int y);
	void SetTerrain(int x, int y, Terrain::Base* terrain);

	//Settings
	int GetLength();
	int GetWidth();
	int GetAmplitude();

	void SetLowestPoint(int z);
	int GetLowestPoint();
	
};