/**
 * @file map.cpp
 * @author  Adam Jędrzejowski <a.jedrzejowski@gmail.com>
 * @version 2.0
 *
 * @section LICENSE
 *
 * Copyright (C) 2016 Adam Jędrzejowski <a.jedrzejowski@gmail.com>
 * This file is part of map-creator
 *
 * map-creator can not be copied and/or distributed without the express
 * permission of Adam Jędrzejowski
 *
 * @section DESCRIPTION
 *
 * Plik z ciałami klasy Map
 */

#include "map.h"

using namespace std;

Map::Map(){
	mapSettings = new Settings();
};

Map& Map::GetInstance(){
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

void Map::GenerateSurface() {

	cout << "Randomizing surface ..." << endl;

	PerlinNoise noise = PerlinNoise(
		Settings::GetPersistence(),
		Settings::GetFrequency(),
		Settings::GetAmplitude(),
		Settings::GetOctaves(),
		Settings::GetRandomseed());

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

void Map::DrawMap(string path) {
	cout << "Drawing ..." << endl;

	int w, h;

	Svg::SvgImage* outputImage = new Svg::SvgImage(
		Point::Transform(0, 0, Settings::GetAmplitude()).X + Point::Transform(Settings::GetWidth(), Settings::GetLength(), -Settings::GetAmplitude()).X,
		Point::Transform(0, 0, Settings::GetAmplitude()).Y + Point::Transform(Settings::GetWidth(), Settings::GetLength(), -Settings::GetAmplitude()).Y);

	//Watermark
	outputImage->AddText(Svg::Text("Map Creator", Svg::Color(), 100, 100));
	outputImage->AddText(Svg::Text("by Adam Jedrzejowski", Svg::Color(), 100, 120));

	Svg::StyleClass styleClass = Svg::StyleClass("polygon");
	styleClass.Set("stroke-width", "0.5");
	styleClass.Set("stroke", "white");
	outputImage->AddClass(styleClass);

	for (int x = 0; x < Settings::GetWidth(); x++) {
		for (int y = 0; y < Settings::GetLength(); y++) {
			Terrain::Base* temp = GetTerrain(x, y);

			if (temp != NULL) {
				temp->DrawOn(outputImage);
				temp->InsertDefs(outputImage);
			}
		}
	}

	outputImage->Save(path);
}
