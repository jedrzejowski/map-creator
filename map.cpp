#include "header.h"

using namespace std;

void Map::expandMap(int w, int h) {

	mapArray = new Terrain*[w];
	if (w > Width) {
		mapArray = (Terrain **)realloc(mapArray, sizeof(Terrain*)*w);
		for (int i = Width; i < w; i++) {
			mapArray[i] = new Terrain[5];
		}

		Width = w;
	}

	if (h > Height) {
		for (int i = 0; i < Width; i++) {
			//mapArray[i] = new Terrain[h];
			//cout << i << endl;
			if (mapArray[i] == NULL) {
				//continue;
			}
			mapArray[i] = (Terrain *)realloc(mapArray[i], sizeof(Terrain)*10);
		}

		Height = h;
	}

	//cout << "w:" << sizeof mapArray / sizeof mapArray[0] << " c:" << sizeof mapArray[0] / sizeof(Terrain) << endl;
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

	ifstream file (path);

	//Wczytywanie ca³ej mapy
	int w = 0, h = 0;
	char color[16];
	Terrain * tempTerrain;
	stringstream stream;
	string line;

	while (getline(file, line)){//Height
		h++;

		for (int i = 0, n = 0; i < line.length(); i++){
			stream << line[i];

			if (line[i] == ';') {
				n++;

				if (n > w) w = n;

				expandMap(w, h);
				getTerrain(n - 1, -1);
				stream.str(std::string());
			}
		}

			/*tempTerrain = getTerrain(w, h);

			wrong = fscanf(file, "%d:%[^;];", &seaLvl, color);
			if (!wrong) {
				printf("B³¹d podczas wczycztywania mapy");
				exit(2);
			}

			tempTerrain->Color = string(color);
			tempTerrain->Height = seaLvl;
			*/
			//setHighestPoint(seaLvl);
			//setLowestPoint(seaLvl);
	};

	cout << "qq" << endl;

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
				terrain->Color);

			//poziom morza
			if (terrain->Height < 0) {
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
					terrain->Color);
			} else {
				svg.addPolygon(
					Point::Transform(w + 1, h + 1, terrain->Height),
					Point::Transform(w + 1, h, terrain->Height),
					Point::Transform(w + 1, h, LowestPoint),
					Point::Transform(w + 1, h + 1, LowestPoint),
					terrain->Color);
			}

			if (h + 1 < Height) {
				svg.addPolygon(
					Point::Transform(w, h + 1, terrain->Height),
					Point::Transform(w + 1, h + 1, terrain->Height),
					Point::Transform(w + 1, h + 1, getTerrain(w, h + 1)->Height),
					Point::Transform(w, h + 1, getTerrain(w, h + 1)->Height),
					terrain->Color);
			} else {
				svg.addPolygon(
					Point::Transform(w, h + 1, terrain->Height),
					Point::Transform(w + 1, h + 1, terrain->Height),
					Point::Transform(w + 1, h + 1, LowestPoint),
					Point::Transform(w, h + 1, LowestPoint),
					terrain->Color);
			}
		};
	};
	svg.save(path);
};

