#pragma once
#include "header.h"

#define DEFAULT_INPUT_FILE "input.ini"

#define DEFAULT_MAP_WIDTH 50
#define DEFAULT_MAP_LENGTH 50
#define DEFAULT_MAP_AMPLITUDE 50
#define DEFAULT_MAP_PERSISTENCE 1
#define DEFAULT_MAP_FREQUENCY 0.05
#define DEFAULT_MAP_OCTAVES 3

using namespace std;

class Settings {
	friend class Map;
	int Width, Length;
	int LowestPoint;

	double Persistence, Frequency, Amplitude;
	int Octaves, Randomseed;

	bool LowGraphic = false;
public:

	Settings();

	void ReadFromFile(string path);

	static int GetLength();
	static int GetWidth();

	static double GetPersistence();
	static double GetFrequency();
	static double GetAmplitude();
	static int GetOctaves();
	static int GetRandomseed();

	static void SetLowestPoint(int z);
	static int GetLowestPoint();


	static bool IsLowGraphic();
	static bool SmoothTerrainCross();

};
