#include "header.h"

using namespace std;

void Map::GenerateSurface() {

	cout << "Randomizing surface ..." << endl;

	PerlinNoise noise = PerlinNoise(
		mapSettings->Persistence, 
		mapSettings->Frequency,
		mapSettings->Amplitude,
		mapSettings->Octaves, 
		mapSettings->Randomseed);

	for (int i = 0; i < Settings::GetWidth(); i++) {
		surface.push_back(vector<Terrain::Base*>());

		for (int j = 0; j < Settings::GetLength(); j++) {
			surface.at(i).push_back(new Terrain::Base(i, j, noise.GetHeight(i, j)));
		}
	}

	cout << "Initialization ..." << endl;

	for (int i = 0; i < Settings::GetWidth(); i++)
		for (int j = 0; j < Settings::GetLength(); j++) {
			surface.at(i).at(j)->Init();
		}

}