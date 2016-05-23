#include "map.h"

void Map::DrawMap(string path) {
	cout << "Drawing ..." << endl;

	outputImage = new Svg::SvgImage(100000, 100000);

	Svg::StyleClass styleClass = Svg::StyleClass("polygon");
	styleClass.Set("stroke-width", "0.5");
	styleClass.Set("stroke", "white");
	outputImage->AddClass(styleClass);

	for (int x = 0; x < Settings::GetWidth(); x++) {
		for (int y = 0; y < Settings::GetLength(); y++) {
			Terrain::Base* temp = GetTerrain(x, y);

			if(temp != NULL)
			temp->DrawOn(outputImage);
			temp->InsertDefs(outputImage);
		}
	}

	outputImage->save(path);
}