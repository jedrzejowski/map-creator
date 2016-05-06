#include "header.h"

void Map::DrawMap(string path) {

	for (int x = 0; x < getWidth(); x++) {
		surface.push_back(vector<BaseTerrain>());

		for (int y = 0; y < getLength(); y++) {
			int Height = getTerrain(x, y).getZ();

			outputImage->addPolygon(
				Point::Transform(x, y, Height),
				Point::Transform(x, y + 1, Height),
				Point::Transform(x + 1, y + 1, Height),
				Point::Transform(x + 1, y, Height),
				"green");

			if (x + 1 < Map::GetInstance().getWidth()) {
				outputImage->addPolygon(
					Point::Transform(x + 1, y + 1, Height),
					Point::Transform(x + 1, y, Height),
					Point::Transform(x + 1, y, Map::GetInstance().getTerrain(x + 1, y).getZ()),
					Point::Transform(x + 1, y + 1, Map::GetInstance().getTerrain(x + 1, y).getZ()),
					"green");
			}

			if (y + 1 < Map::GetInstance().getLength()) {
				outputImage->addPolygon(
					Point::Transform(x, y + 1, Height),
					Point::Transform(x + 1, y+ 1, Height),
					Point::Transform(x + 1, y + 1, Map::GetInstance().getTerrain(x, y + 1).getZ()),
					Point::Transform(x, y + 1, Map::GetInstance().getTerrain(x, y + 1).getZ()),
					"green");
			}
		}
	}

	outputImage->save(path);
}