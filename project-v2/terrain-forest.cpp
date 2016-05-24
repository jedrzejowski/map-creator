#include "header.h"

namespace Terrain {
	Forest::Forest(Land* base) {

		// Sprawdza ko³o wokó³ pola
		for (int x = -FOREST_RANGE; x < FOREST_RANGE; x++) {
			for (int y = -FOREST_RANGE; y < FOREST_RANGE; y++) {
				if(sqrt(x*x+y*y)<=FOREST_RANGE)
					if (typeid(*Map::GetTerrain(base->GetX() + x, base->GetY() + y)) != typeid(Land)) {
						goto Suicide;
					}
			}
		}

		for (int x = -FOREST_RANGE; x < FOREST_RANGE; x++) {
			for (int y = -FOREST_RANGE; y < FOREST_RANGE; y++) {
				if (sqrt(x*x + y*y) <= FOREST_RANGE)
					new Forest(Map::GetTerrain(base->GetX() + x, base->GetY() + y));
			}
		}
		
		
	Suicide:
		delete this;
	}

	Forest::Forest(Base* base) {
		InsertConstructor(base);	
	}

	bool Forest::TreeSeed() {
		return rand() % 100 == 0 ? true : false;
	}

	std::string Forest::GetSurfaceClasses() {
		return Land::GetSurfaceClasses().append(" forest");
	}

	void Forest::DrawOn(Svg::SvgImage* svgImage) {
		Land::DrawOn(svgImage);

		if (rand() % 5 == 0) return;

		Svg::Polygon polygon = Svg::Polygon();

		polygon.Clear();
		polygon.AddPoint(Point::Transform(GetX() + 0.8, GetY() + 0.2, GetZ()));
		polygon.AddPoint(Point::Transform(GetX() + 0.2, GetY() + 0.8, GetZ()));
		polygon.AddPoint(Point::Transform(GetX() + 0.5, GetY() + 0.5, GetZ() + 30));
		polygon.AddClass("tree forest");
		svgImage->AddPolygon(polygon);

		polygon.Clear();
		polygon.AddPoint(Point::Transform(GetX() + 0.5, GetY() + 0.5, GetZ()));
		polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, GetZ()));
		polygon.AddPoint(Point::Transform(GetX() + 0.5, GetY() + 0.5, GetZ() + 30));
		polygon.AddClass("tree forest");
		svgImage->AddPolygon(polygon);

	}

	void Forest::InsertDefs(Svg::SvgImage* svgImage) {
		static bool inserted = false;
		if (inserted) return;
		inserted = true;

		Svg::StyleClass styleClass;

		styleClass = Svg::StyleClass(".tree.forest");
		styleClass.Set("fill", Land::GetSurfaceColor().Darken(0.3).ToString());
		svgImage->AddClass(styleClass);
	}
};