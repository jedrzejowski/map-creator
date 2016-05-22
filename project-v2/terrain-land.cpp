#include "header.h"
#include "terrain.h"

namespace Terrain {
	Land::Land(Base* base) {
		InsertConstructor(base);

		static float bleachLvl = Map::GetInstance().GetAmplitude() * 0.1;
		if (GetZ() < bleachLvl) {
			new Sand(this);
		}

		static float rockLvl = Map::GetInstance().GetAmplitude() * 0.7;
		if (GetZ() > rockLvl) {
			new Rocky(this);
		}
	}

	Svg::Color Land::GetSurfaceColor() {
		return Svg::Color(126, 184, 88);
	}

	std::string Land::GetSurfaceClasses() {
		return "land";
	}

	std::string Land::GetSurfaceXClasses() {
		return "x";
	}

	std::string Land::GetSurfaceYClasses() {
		return "y";
	}

	void Land::InsertStyle(Svg::SvgImage* svgImage) {
		static bool inserted = false;
		if (inserted) return;
		inserted = true;

		Svg::StyleClass styleClass;

		styleClass = Svg::StyleClass(".land");
		styleClass.Set("fill", Land::GetSurfaceColor().ToString());
		svgImage->AddClass(styleClass);

		styleClass = Svg::StyleClass(".land.x");
		styleClass.Set("fill", Land::GetSurfaceColor().Darken(0.1).ToString());
		svgImage->AddClass(styleClass);

		styleClass = Svg::StyleClass(".land.y");
		styleClass.Set("fill", Land::GetSurfaceColor().Lighten(0.1).ToString());
		svgImage->AddClass(styleClass);
	}
};