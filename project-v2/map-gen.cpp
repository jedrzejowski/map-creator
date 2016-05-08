#include "header.h"

using namespace std;

void Map::GenerateSurface() {

	PerlinNoise noise = PerlinNoise(
		mapSettings->Persistence, 
		mapSettings->Frequency,
		mapSettings->Amplitude,
		mapSettings->Octaves, 
		mapSettings->Randomseed);

	for (int i = 0; i < GetWidth(); i++) {
		surface.push_back(vector<BaseTerrain*>());

		for (int j = 0; j < GetLength(); j++) {
			surface.at(i).push_back(new BaseTerrain(i, j, noise.GetHeight(i, j)));
		}
	}

	for (int i = 0; i < GetWidth(); i++) 
		for (int j = 0; j < GetLength(); j++) {
			surface.at(i).at(j)->Init();
		}

}