#include "map.h"

using namespace std;

Map::Map(){
	mapSettings = new Settings();
};

Map& Map::GetInstance()
{
	static Map instance = Map();
	return instance;
}


void Map::SetArgs(int argc, char* argv[]) {
	if (argc == 1) {
		cout << ANSI_COLOR_MAGENTA "Default input file: 'input.ini'" ANSI_COLOR_RESET << endl;
		
		mapSettings->ReadFromFile(DEFAULT_INPUT_FILE);
		return;
	}

	if (argc == 2) {
		mapSettings->ReadFromFile(string(argv[1]));
		return;
	}

	if (argc > 2) {
		cerr << "To many arguments" << endl;
		exit(ErrorArgs);
	}
}

Terrain::Base* Map::GetTerrain(int x, int y) {
	if (x < 0) x = 0;
	if (y < 0) y = 0;

	if (x >= Settings::GetWidth()) x = Settings::GetWidth() - 1;
	if (y >= Settings::GetLength()) y = Settings::GetLength() - 1;

	return GetInstance().surface.at(x).at(y);
}

void Map::SetTerrain(int x, int y, Terrain::Base* terrain) {
	GetInstance().surface.at(x).at(y) = terrain;
}