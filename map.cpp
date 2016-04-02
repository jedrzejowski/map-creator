#include "header.h"

using namespace std;

void Map::initMapArray() {
	mapArray = new Terrain*[Width];
	for (int i = 0; i < Width; ++i)
		mapArray[i] = new Terrain[Height];
};

Terrain * Map::getTerrain(int x, int y) {
	return &mapArray[x][y];
};

void Map::setHighestPoint(int z) {
	HighestPoint = z > HighestPoint ? z : HighestPoint;
};

void Map::setLowestPoint(int z) {
	LowestPoint = z < LowestPoint ? z : LowestPoint;
};

void Map::readMapFromFile(string path) {
	int wrong;

	FILE * file = fopen(path.c_str(), "r");

	//Wczytywanie wieloœci mapy
	wrong = fscanf(file, "%dx%d", &Width, &Height);
	if (!wrong) {
		puts("B³¹d podczas wczycztywania wielkoœci mapy");
		exit(1);
	}
	initMapArray();

	//Wczytywanie ca³ej mapy
	int seaLvl;
	char color[16];
	Terrain * tempTerrain;

	for (int h = 0; h < Height; h++) {

		for (int w = 0; w < Width; w++) {

			tempTerrain = getTerrain(w, h);

			wrong = fscanf(file, "%d:%16[^;];", &seaLvl, color);
			if (!wrong) {
				printf("B³¹d podczas wczycztywania mapy");
				exit(2);
			}
			
			//cout << seaLvl << ":" << color << ";";

			tempTerrain->Color = string(color);
			tempTerrain->Height = seaLvl;

			setHighestPoint(seaLvl);
			setLowestPoint(seaLvl);
		}; 
		fscanf(file, "");
		//cout << endl;
	};

	fclose(file);
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
				terrain->Color);

			if (terrain->Height < 0) {
				svg.addPolygon(
					Point::Transform(w, h),
					Point::Transform(w, h + 1),
					Point::Transform(w + 1, h + 1),
					Point::Transform(w + 1, h),
					"rgba(173,216,230,0.5)");
			}

			//Przejœcia terenowe
			if (w + 1 < Width) {
				svg.addPolygon(
					Point::Transform(w + 1, h + 1, terrain->Height),
					Point::Transform(w + 1, h, terrain->Height),
					Point::Transform(w + 1, h, getTerrain(w + 1, h)->Height),
					Point::Transform(w + 1, h + 1, getTerrain(w + 1, h)->Height),
					terrain->Color);
			}

			if (h + 1 < Height) {
				svg.addPolygon(
					Point::Transform(w, h + 1, terrain->Height),
					Point::Transform(w + 1, h + 1, terrain->Height),
					Point::Transform(w + 1, h + 1, getTerrain(w, h + 1)->Height),
					Point::Transform(w, h + 1, getTerrain(w, h + 1)->Height),
					terrain->Color);
			}
		};
	};
	svg.save(path);
};

