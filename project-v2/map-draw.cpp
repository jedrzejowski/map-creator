#include "header.h"

void Map::DrawMap(string path) {
	outputImage = new Svg(100000, 100000);

	for (int x = 0; x < GetWidth(); x++) {
		for (int y = 0; y < GetLength(); y++) {
			BaseTerrain* temp = GetTerrain(x, y);

			if(temp != NULL)
			temp->DrawOn(outputImage);
		}
	}

	outputImage->save(path);
}