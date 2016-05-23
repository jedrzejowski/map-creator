#pragma once
#include "header.h"

class Map {
	friend class Settings;
private:
	Map();

	vector<vector<Terrain::Base*>> surface;
	Svg::SvgImage* outputImage;

	int LowestPoint;
	Settings* mapSettings;

public:
	static Map& GetInstance();

	void SetArgs(int argc, char* argv[]);

	void GenerateSurface();
	void DrawMap(string path);

	static Terrain::Base* GetTerrain(int x, int y);
	static void SetTerrain(int x, int y, Terrain::Base* terrain);


};