#pragma once
#include "header.h"

using namespace std;

class Settings {
public:
	int X, Y, Z1, Z2;

	double persistence, frequency, amplitude;
	int octaves, randomseed;

	Settings();

	void ReadFromFile(string path);
};
