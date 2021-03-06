 /**
  * @file map.cpp
  * @author  Adam Jędrzejowski <a.jedrzejowski@gmail.com>
  * @version 1.0
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

#include "header.h"

using namespace std;

Map::Map(){

};

Map& Map::getInstance()
{
	static Map instance = Map();
	return instance;
}

Terrain * Map::getTerrain(int x, int y) {
	Terrain * temp = mapArray;
	for (int i = 0; i < x + y*Width; i++){
		temp = temp->Next;
	}
	return temp;
};

void Map::addTerrain(Terrain *terrain) {
	if (mapArray == NULL) {
		mapArray = terrain;
		return;
	}

	Terrain * temp = mapArray;
	while (true)
	{
		if (temp->Next == NULL) {

			temp->Next = terrain;

			return;
		}

		temp = temp->Next;
	}
};

void Map::setHighestPoint(int z) {
	HighestPoint = z > HighestPoint ? z : HighestPoint;
};

void Map::setLowestPoint(int z) {
	LowestPoint = z < LowestPoint ? z : LowestPoint;
};

void Map::readMapFromFile(string path) {

	ifstream file(path);

	//Wczytywanie całej mapy
	stringstream stream;
	string line;
	Terrain* tempTerrain;

	while (getline(file, line)) {//Height

		for (int i = 0, n = 0; i < line.length(); i++) {

			stream << line[i];

			if (line[i] == ';') {

				tempTerrain = Terrain::Create(stream);

				tempTerrain->X = n;
				tempTerrain->Y = Height;

				addTerrain(tempTerrain);


				n++;
				if (n > Width) Width++;
				stream.str(std::string());
			}

		};

		Height++;
	};

	file.close();
};

void Map::generateMap(string path) {
	Svg svg = Svg(
		Point::Transform(Width + 2, 0, LowestPoint).X,
		Point::Transform(Width + 2, Height + 2, LowestPoint).Y
		);

	for (int h = 0; h < Height; h++) {

		for (int w = 0; w < Width; w++) {

			getTerrain(w, h)->drawInSvg(svg);

		};
	};

	svg.save(path);
};
