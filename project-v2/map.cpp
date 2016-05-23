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

void Map::DrawMap(string path) {
	cout << "Drawing ..." << endl;

	outputImage = new Svg::SvgImage(100000, 100000);

	Svg::StyleClass styleClass = Svg::StyleClass("polygon");
	styleClass.Set("stroke-width", "0.5");
	styleClass.Set("stroke", "white");
	outputImage->AddClass(styleClass);

	for (int x = 0; x < Settings::GetWidth(); x++) {
		for (int y = 0; y < Settings::GetLength(); y++) {
			Terrain::Base* temp = GetTerrain(x, y);

			if (temp != NULL)
				temp->DrawOn(outputImage);
			temp->InsertDefs(outputImage);
		}
	}

	outputImage->save(path);
}

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
			surface.at(i).push_back(new Terrain::Base());
			new Terrain::Base(i, j, noise.GetHeight(i, j));
		}
	}

	cout << "Initialization ..." << endl;

	for (int i = 0; i < Settings::GetWidth(); i++)
		for (int j = 0; j < Settings::GetLength(); j++) {
			surface.at(i).at(j)->Init();
		}

}