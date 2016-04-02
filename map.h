#pragma once
#include "header.h"

using namespace std;

class Map {
private:
	Terrain** mapArray;
public:
	int Height, Width, HighestPoint, LowestPoint;


public:
	void initMapArray();
	void readMapFromFile(string path);
	Terrain * getTerrain(int x, int y);
	void generateMap(string path);
	void setHighestPoint(int z);
	void setLowestPoint(int z);
};