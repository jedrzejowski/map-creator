#include "header.h"

namespace Terrain {

	Deep::Deep(Water* base) {
		InsertConstructor(base);
	}

	Svg::Color Deep::GetWaterColor() {
		return Svg::Color(124, 183, 243, 0.75);
	}

	std::string Deep::GetWaterClasses() {
		return "water deep";
	}

	void Deep::InsertStyle(Svg::SvgImage* svgImage) {
		static bool inserted = false;
		if (inserted) return;
		inserted = true;

		Svg::StyleClass styleClass;

		styleClass = Svg::StyleClass(".water.deep");
		styleClass.Set("fill", GetWaterColor().ToString());
		svgImage->AddClass(styleClass);

	}
}