#include "header.h"

using namespace std;

extern Map map;

void Terrain::setHeight(int seaLvl) {
	Height = seaLvl;

	if (seaLvl < 0)Water = true;

	map.setHighestPoint(seaLvl);
	map.setLowestPoint(seaLvl);
};

string Terrain::getSvgColor() {
	return "red";
}

template <char C>
std::istream& expect(std::istream& in)
{
	if ((in >> std::ws).peek() == C) {
		in.ignore();
	}
	else {
		in.setstate(std::ios_base::failbit);
	}
	return in;
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

		//wygladzanie koñcza poziomu morza
		if (X + 1 == map.Width) {
			svg.addPolygon(
				Point::Transform(X + 1, Y + 1),
				Point::Transform(X + 1, Y),
				Point::Transform(X + 1, Y, Height),
				Point::Transform(X + 1, Y + 1, Height),
				"rgba(173,216,230,0.5)");
		}

		if (Y + 1 == map.Height) {
			svg.addPolygon(
				Point::Transform(X, Y + 1),
				Point::Transform(X + 1, Y + 1),
				Point::Transform(X + 1, Y + 1, Height),
				Point::Transform(X, Y + 1, Height),
				"rgba(173,216,230,0.5)");
		}
	}

	//Przejœcia terenowe
	if (X + 1 < map.Width) {
		svg.addPolygon(
			Point::Transform(X + 1, Y + 1, Height),
			Point::Transform(X + 1, Y, Height),
			Point::Transform(X + 1, Y, map.getTerrain(X + 1, Y)->Height),
			Point::Transform(X + 1, Y + 1, map.getTerrain(X + 1, Y)->Height),
			getSvgColor());
	}
	else {
		svg.addPolygon(
			Point::Transform(X + 1, Y + 1, Height),
			Point::Transform(X + 1, Y, Height),
			Point::Transform(X + 1, Y, map.LowestPoint),
			Point::Transform(X + 1, Y + 1, map.LowestPoint),
			getSvgColor());
	}

	if (Y + 1 < map.Height) {
		svg.addPolygon(
			Point::Transform(X, Y + 1, Height),
			Point::Transform(X + 1, Y + 1, Height),
			Point::Transform(X + 1, Y + 1, map.getTerrain(X, Y + 1)->Height),
			Point::Transform(X, Y + 1, map.getTerrain(X, Y + 1)->Height),
			getSvgColor());
	}
	else {
		svg.addPolygon(
			Point::Transform(X, Y + 1, Height),
			Point::Transform(X + 1, Y + 1, Height),
			Point::Transform(X + 1, Y + 1, map.LowestPoint),
			Point::Transform(X, Y + 1, map.LowestPoint),
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
