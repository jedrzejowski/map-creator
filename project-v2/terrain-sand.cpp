#include "header.h"

namespace Terrain {
	Sand::Sand(Land* base) {
		InsertConstructor(base);
	}

	Svg::Color Sand::GetSurfaceColor() {
		return Svg::Color(255, 200, 0);
	}

	std::string Sand::GetSurfaceClasses() {
		return "sand";
	}

	std::string Sand::GetSurfaceXClasses() {
		return "x";
	}

	std::string Sand::GetSurfaceYClasses() {
		return "y";
	}

	std::string Sand::GetName() {
		return "sand";
	}

	void Sand::InsertDefs(Svg::SvgImage* svgImage) {
		static bool inserted = false;
		if (inserted) return;
		inserted = true;

		Svg::StyleClass styleClass;

		styleClass = Svg::StyleClass(".sand");
		styleClass.Set("fill", Sand::GetSurfaceColor().ToString());
		svgImage->AddClass(styleClass);

		styleClass = Svg::StyleClass(".sand.x");
		styleClass.Set("fill", Sand::GetSurfaceColor().Darken(0.1).ToString());
		svgImage->AddClass(styleClass);

		styleClass = Svg::StyleClass(".sand.y");
		styleClass.Set("fill", Sand::GetSurfaceColor().Lighten(0.1).ToString());
		svgImage->AddClass(styleClass);
	}
}