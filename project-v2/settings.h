#pragma once
#include "header.h"

using namespace std;

class Settings {
	friend class Map;

public:
	int Width, Length;

	double Persistence, Frequency, Amplitude;
	int Octaves, Randomseed;

	bool LowGraphic = false;

	Settings();

	void ReadFromFile(string path);

	//statics
	static int GetLength();
	static int GetWidth();
	static int GetAmplitude();

	static void SetLowestPoint(int z);
	static int GetLowestPoint();
	static bool IsLowGraphic();
	static bool SmoothTerrainCross();

};
