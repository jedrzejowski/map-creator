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

	std::string Land::GetName() {
		return "land";
	}

	void Land::InsertDefs(Svg::SvgImage* svgImage) {
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

		//Land 2 Land
		styleClass = Svg::StyleClass(".land.x.land2land");
		styleClass.Set("fill", "url(#xland2land)");
		svgImage->AddClass(styleClass);
		styleClass = Svg::StyleClass(".land.y.land2land");
		styleClass.Set("fill", "url(#yland2land)");
		svgImage->AddClass(styleClass);

		Svg::LinearGradient gradient;

		gradient = Svg::LinearGradient("xland2land");
		gradient.SetPath(0.5, 0, 0.5, 1);
		gradient.AddStop(Svg::GradientStop(0, Land::GetSurfaceColor()));
		gradient.AddStop(Svg::GradientStop(0.4, Land::GetSurfaceColor().Darken(0.1)));
		gradient.AddStop(Svg::GradientStop(1, Svg::Color(173, 124, 86)));
		svgImage->AddGradient(gradient);

		gradient = Svg::LinearGradient("yland2land");
		gradient.SetPath(0.5, 0, 0.5, 1);
		gradient.AddStop(Svg::GradientStop(0, Land::GetSurfaceColor()));
		gradient.AddStop(Svg::GradientStop(0.4, Land::GetSurfaceColor().Lighten(0.1)));
		gradient.AddStop(Svg::GradientStop(1, Svg::Color(173, 124, 86)));
		svgImage->AddGradient(gradient);
	}
};