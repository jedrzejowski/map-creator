/**
 * @file terrain.cpp
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
 * Plik z ciałami klasy Terrain
 */

#include "header.h"

using namespace std;

void Terrain::setHeight(int seaLvl) {
	Height = seaLvl;

	if (seaLvl < 0)Water = true;

	Map::getInstance().setHighestPoint(seaLvl);
	Map::getInstance().setLowestPoint(seaLvl);
};

string Terrain::getSvgColor() {
	return "red";
}

Terrain* Terrain::Create(stringstream&data) {
	string type, texture, seaLvl;

	getline(data, seaLvl, ':');
	getline(data, type, ':');
	getline(data, texture, ';');

	Terrain *output;

		 if (!type.compare("forest")) output = new ForestTerrain();
	else if (!type.compare("mountain")) output = new MountainTerrain();
	else if (!type.compare("sand")) output = new SandTerrain();
	else cout << "error";

	output->setHeight(stoi(seaLvl));
	output->Type = type;
	output->Texture = texture;

	return output;
};

void Terrain::drawInSvg(Svg &svg) {

	svg.addPolygon(
		Point::Transform(X, Y, Height),
		Point::Transform(X, Y + 1, Height),
		Point::Transform(X + 1, Y + 1, Height),
		Point::Transform(X + 1, Y, Height),
		getSvgColor());

	//poziom morza
	if (Water) {

		svg.addPolygon(
			Point::Transform(X, Y),
			Point::Transform(X, Y + 1),
			Point::Transform(X + 1, Y + 1),
			Point::Transform(X + 1, Y),
			"rgba(173,216,230,0.5)");

		//wygladzanie ko�cza poziomu morza
		if (X + 1 == Map::getInstance().Width) {
			svg.addPolygon(
				Point::Transform(X + 1, Y + 1),
				Point::Transform(X + 1, Y),
				Point::Transform(X + 1, Y, Height),
				Point::Transform(X + 1, Y + 1, Height),
				"rgba(173,216,230,0.5)");
		}

		if (Y + 1 == Map::getInstance().Height) {
			svg.addPolygon(
				Point::Transform(X, Y + 1),
				Point::Transform(X + 1, Y + 1),
				Point::Transform(X + 1, Y + 1, Height),
				Point::Transform(X, Y + 1, Height),
				"rgba(173,216,230,0.5)");
		}
	}

	//Przej�cia terenowe
	if (X + 1 < Map::getInstance().Width) {
		svg.addPolygon(
			Point::Transform(X + 1, Y + 1, Height),
			Point::Transform(X + 1, Y, Height),
			Point::Transform(X + 1, Y, Map::getInstance().getTerrain(X + 1, Y)->Height),
			Point::Transform(X + 1, Y + 1, Map::getInstance().getTerrain(X + 1, Y)->Height),
			getSvgColor());
	}
	else {
		svg.addPolygon(
			Point::Transform(X + 1, Y + 1, Height),
			Point::Transform(X + 1, Y, Height),
			Point::Transform(X + 1, Y, Map::getInstance().LowestPoint),
			Point::Transform(X + 1, Y + 1, Map::getInstance().LowestPoint),
			getSvgColor());
	}

	if (Y + 1 < Map::getInstance().Height) {
		svg.addPolygon(
			Point::Transform(X, Y + 1, Height),
			Point::Transform(X + 1, Y + 1, Height),
			Point::Transform(X + 1, Y + 1, Map::getInstance().getTerrain(X, Y + 1)->Height),
			Point::Transform(X, Y + 1, Map::getInstance().getTerrain(X, Y + 1)->Height),
			getSvgColor());
	}
	else {
		svg.addPolygon(
			Point::Transform(X, Y + 1, Height),
			Point::Transform(X + 1, Y + 1, Height),
			Point::Transform(X + 1, Y + 1, Map::getInstance().LowestPoint),
			Point::Transform(X, Y + 1, Map::getInstance().LowestPoint),
			getSvgColor());
	}
};

string MountainTerrain::getSvgColor() {
	if (!Texture.compare("dark")) return "gray";

	return "lightgray";
}

string ForestTerrain::getSvgColor() {
	if (!Texture.compare("dark")) return "darkgreen";

	return "forestgreen";
}

string SandTerrain::getSvgColor() {
	return "gold";
}
