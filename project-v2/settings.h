#pragma once
#include "header.h"

using namespace std;

class Settings {
public:
	int Width, Length;

	double Persistence, Frequency, Amplitude;
	int Octaves, Randomseed;

	bool LowGraphic = false;

	Settings();

	void ReadFromFile(string path);
};
