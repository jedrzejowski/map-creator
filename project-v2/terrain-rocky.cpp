#include "header.h"

namespace Terrain {
	Rocky::Rocky(Land* base) {
		InsertConstructor(base);
	}

	Svg::Color Rocky::GetSurfaceColor() {
		return Svg::Color(200, 200, 200);
	}

	std::string Rocky::GetSurfaceClasses() {
		return "rocky";
	}

	std::string Rocky::GetSurfaceXClasses() {
		return "rocky";
	}

	std::string Rocky::GetSurfaceYClasses() {
		return "rocky";
	}

	void Rocky::InsertStyle(Svg::SvgImage* svgImage) {
		static bool inserted = false;
		if (inserted) return;
		inserted = true;

		Svg::StyleClass styleClass;

		styleClass = Svg::StyleClass(".rocky");
		styleClass.Set("fill", Rocky::GetSurfaceColor().ToString());
		styleClass.Set("stroke", "black");
		svgImage->AddClass(styleClass);

		styleClass = Svg::StyleClass(".rocky.x");
		styleClass.Set("fill", Rocky::GetSurfaceColor().Darken(0.1).ToString());
		svgImage->AddClass(styleClass);

		styleClass = Svg::StyleClass(".rocky.y");
		styleClass.Set("fill", Rocky::GetSurfaceColor().Lighten(0.1).ToString());
		svgImage->AddClass(styleClass);
	}
};
