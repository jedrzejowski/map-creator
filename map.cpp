#include "header.h"

using namespace std;

void Map::initMapArray() {
};

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
	int wrong;

	ifstream file(path);

	//Wczytywanie ca³ej mapy
	stringstream stream;
	string line;

	while (getline(file, line)) {//Height

		for (int i = 0, n = 0; i < line.length(); i++) {
			stream << line[i];

			if (line[i] == ';') {
				n++;

				if (n > Width) Width++;

				addTerrain(Terrain::Create(stream));
				
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
	Terrain * terrain;


	for (int h = 0; h < Height; h++) {

		for (int w = 0; w < Width; w++) {

			terrain = getTerrain(w, h);

			svg.addPolygon(
				Point::Transform(w, h, terrain->Height),
				Point::Transform(w, h + 1, terrain->Height),
				Point::Transform(w + 1, h + 1, terrain->Height),
				Point::Transform(w + 1, h, terrain->Height),
				terrain->getSvgColor());

			//poziom morza
			if (terrain->Water) {

				svg.addPolygon(
					Point::Transform(w, h),
					Point::Transform(w, h + 1),
					Point::Transform(w + 1, h + 1),
					Point::Transform(w + 1, h),
					"rgba(173,216,230,0.5)");

				//wygladzanie koñcza poziomu morza
				if (w + 1 == Width) {
					svg.addPolygon(
						Point::Transform(w + 1, h + 1),
						Point::Transform(w + 1, h),
						Point::Transform(w + 1, h, terrain->Height),
						Point::Transform(w + 1, h + 1, terrain->Height),
						"rgba(173,216,230,0.5)");
				}

				if (h + 1 == Height) {
					svg.addPolygon(
						Point::Transform(w, h + 1),
						Point::Transform(w + 1, h + 1),
						Point::Transform(w + 1, h + 1, terrain->Height),
						Point::Transform(w, h + 1, terrain->Height),
						"rgba(173,216,230,0.5)");
				}
			}

			//Przejœcia terenowe
			if (w + 1 < Width) {
				svg.addPolygon(
					Point::Transform(w + 1, h + 1, terrain->Height),
					Point::Transform(w + 1, h, terrain->Height),
					Point::Transform(w + 1, h, getTerrain(w + 1, h)->Height),
					Point::Transform(w + 1, h + 1, getTerrain(w + 1, h)->Height),
					terrain->getSvgColor());
			} else {
				svg.addPolygon(
					Point::Transform(w + 1, h + 1, terrain->Height),
					Point::Transform(w + 1, h, terrain->Height),
					Point::Transform(w + 1, h, LowestPoint),
					Point::Transform(w + 1, h + 1, LowestPoint),
					terrain->getSvgColor());
			}

			if (h + 1 < Height) {
				svg.addPolygon(
					Point::Transform(w, h + 1, terrain->Height),
					Point::Transform(w + 1, h + 1, terrain->Height),
					Point::Transform(w + 1, h + 1, getTerrain(w, h + 1)->Height),
					Point::Transform(w, h + 1, getTerrain(w, h + 1)->Height),
					terrain->getSvgColor());
			} else {
				svg.addPolygon(
					Point::Transform(w, h + 1, terrain->Height),
					Point::Transform(w + 1, h + 1, terrain->Height),
					Point::Transform(w + 1, h + 1, LowestPoint),
					Point::Transform(w, h + 1, LowestPoint),
					terrain->getSvgColor());
			}
		};
	};
	svg.save(path);
};

