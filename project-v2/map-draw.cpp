#include "header.h"

void Map::DrawMap(string path) {
	outputImage = new Svg(100000, 100000);

	for (int x = 0; x < GetWidth(); x++) {
		for (int y = 0; y < GetLength(); y++) {
			GetTerrain(x, y).DrawOn(outputImage);
		}
	}

	outputImage->save(path);
}