#include "header.h"

using namespace std;

Map::Map(){
	srand(time(NULL));

	mapSettings = new Settings();
};

Map& Map::GetInstance()
{
	static Map instance = Map();
	return instance;
}


void Map::SetArgs(int argc, char* argv[]) {
	if (argc == 1) {
		cout << ANSI_COLOR_MAGENTA  "Default input file: 'input.ini'" ANSI_COLOR_RESET << endl;
		
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

	if (x >= GetWidth()) x = GetWidth() - 1;
	if (y >= GetLength()) y = GetLength() - 1;

	return surface.at(x).at(y);
}

void Map::SetTerrain(int x, int y, Terrain::Base* terrain) {
	surface.at(x).at(y) = terrain;
}