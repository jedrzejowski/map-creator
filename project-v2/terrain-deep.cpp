#include "header.h"

namespace Terrain {

	Deep::Deep(Water* base) {
		InsertConstructor(base);
	}

	Svg::Color Deep::GetSurfaceColor() {
		return Svg::Color(173, 124, 86);//Svg::Color(255, 200, 0);
	}

	Svg::Color Deep::GetWaterColor() {
		return Svg::Color(124, 183, 243, 0.75);
	}

	std::string Deep::GetWaterClasses() {
		return "water deep";
	}

	std::string Deep::GetSurfaceClasses() {
		return "water-bottom deep";
	}

	std::string Deep::GetName() {
		return "deep";
	}

	void Deep::InsertDefs(Svg::SvgImage* svgImage) {
		static bool inserted = false;
		if (inserted) return;
		inserted = true;

		Svg::StyleClass styleClass;

		svgImage->AddClass(Svg::StyleClass::FillClass(
			".water.deep", Deep::GetWaterColor()));

		svgImage->AddClass(Svg::StyleClass::FillClass(
			".water-bottom.deep", Deep::GetSurfaceColor()));

		svgImage->AddClass(Svg::StyleClass::FillClass(
			".water-bottom.x.deep", Deep::GetSurfaceColor().Darken(0.1)));

		svgImage->AddClass(Svg::StyleClass::FillClass(
			".water-bottom.y.deep", Deep::GetSurfaceColor().Lighten(0.1)));
	}
}