#include "header.h"

using namespace std;

void Map::GenerateSurface() {

	PerlinNoise noise = PerlinNoise(
		mapSettings->persistence, 
		mapSettings->frequency, 
		GetHeightDiff(), 
		mapSettings->octaves, 
		mapSettings->randomseed);

	for (int i = 0; i < GetWidth(); i++) {
		surface.push_back(vector<BaseTerrain>());

		for (int j = 0; j < GetLength(); j++) {
			surface.at(i).push_back(BaseTerrain(i, j, noise.GetHeight(i, j)));
			
		}
	}

}