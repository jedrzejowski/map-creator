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

	cout << type;

	return output;
};

string MountainTerrain::getSvgColor() {
	return "gray";
}

string ForestTerrain::getSvgColor() {
	if (!Texture.compare("dark")) return "darkgreen";

	return "forestgreen";
}

string SandTerrain::getSvgColor() {
	return "gold";
}