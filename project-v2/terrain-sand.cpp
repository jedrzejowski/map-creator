#include "header.h"

namespace Terrain {
	Sand::Sand(Land* base) {
		InsertConstructor(base);
	}

	void Sand::Init() {

		float tempRadius;
		for (int x = -SAND_WATER_DISTANCE; x < SAND_WATER_DISTANCE; x++) {
			for (int y = -SAND_WATER_DISTANCE; y < SAND_WATER_DISTANCE; y++) {
				tempRadius = sqrt(x*x + y*y);
				if (tempRadius <= SAND_WATER_DISTANCE)
					if (typeid(*Map::GetTerrain(GetX() + x, GetY() + y)) == typeid(Water)) {
						dist2Water = tempRadius < dist2Water ? tempRadius : dist2Water;
					}
			}
		}
	}

	Svg::Color Sand::GetSurfaceColor() {
		return Svg::Color(255, 200, 0);
	}

	std::string Sand::GetSurfaceClasses() {
		if(dist2Water == SAND_WATER_DISTANCE)
			return "sand";

		return "sand pattern" + to_string((int)dist2Water);
	}

	std::string Sand::GetName() {
		return "sand";
	}

	void Sand::InsertDefs(Svg::SvgImage* svgImage) {
		static bool inserted = false;
		if (inserted) return;
		inserted = true;

		Svg::StyleClass styleClass;

		svgImage->AddClass(Svg::StyleClass::FillClass(
			".sand", Sand::GetSurfaceColor()));
		svgImage->AddClass(Svg::StyleClass::FillClass(
			".sand.x", Sand::GetSurfaceColor().Darken(0.1)));
		svgImage->AddClass(Svg::StyleClass::FillClass(
			".sand.y", Sand::GetSurfaceColor().Lighten(0.1)));

		if (!Settings::IsLowGraphic()){

			for (int i = 0; i < SAND_WATER_DISTANCE; i++) {
				Svg::Color pattern = Sand::GetSurfaceColor().Darken((SAND_WATER_DISTANCE - i) / (SAND_WATER_DISTANCE + 15.0f));
				std::string index = to_string(i);

				svgImage->AddClass(Svg::StyleClass::FillClass(
					".sand.pattern" + index, pattern));
				svgImage->AddClass(Svg::StyleClass::FillClass(
					".sand.x.pattern" + index, pattern.Darken(0.1)));
				svgImage->AddClass(Svg::StyleClass::FillClass(
					".sand.y.pattern" + index, pattern.Lighten(0.1)));
			}
		}
	}
}