#include "header.h"

using namespace std;

Map::Map() {  }

Map& Map::GetInstance()
{
	static Map instance = Map();
	return instance;
}

void Map::SetArgs(int argc, char* argv[]) {
	if (argc == 1) {
		cout << "Default input file: 'input.ini'" << endl;
		mapSettings.readFromFile("input.ini");
	}

	if (argc == 2) {
		mapSettings.readFromFile(string(argv[1]));
	}

	if (argc > 2) {
		cerr << "To many arguments" << endl;
		exit(ErrorArgs);
	}
}

BaseTerrain* Map::getTerrain(int x, int y) {
	if (x < 0) x = 0;
	if (y < 0) y = 0;

	if (x > getWidth()) x = getWidth();
	if (y > getLength()) y = getLength();

	return &surface[x][y];
}

int Map::getWidth() {
	return mapSettings.X;
}

int Map::getLength() {
	return mapSettings.Y;
}

int Map::getMinHeight() {
	return mapSettings.Z1;
}

int Map::getMaxHeight() {
	return mapSettings.Z2;
}

int Map::getHeightDiff() {
	return getMaxHeight() + getMinHeight();
}

double Map::getRoughness() {
	return mapSettings.Roughness;
}