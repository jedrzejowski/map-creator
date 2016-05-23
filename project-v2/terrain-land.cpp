#include "header.h"

namespace Terrain {
	Land::Land(Base* base) {
		InsertConstructor(base);

		static float bleachLvl = Settings::GetAmplitude() * 0.1;
		if (GetZ() < bleachLvl) {
			new Sand(this);
			return;
		}

		static float rockLvl = Settings::GetAmplitude() * 0.7;
		if (GetZ() > rockLvl) {
			new Rocky(this);
			return;
		}
	}

	void Land::Init() {
		if (Forest::TreeSeed()) {
			new Forest(this);
			return;
		}
	}

	Svg::Color Land::GetSurfaceColor() {
		return Svg::Color(126, 184, 88);
	}

	std::string Land::GetSurfaceClasses() {
		return "land";
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

		if (Settings::SmoothTerrainCross()) {
			Svg::LinearGradient gradient;

			//Land 2 Land
			styleClass = Svg::StyleClass(".land.x.land2land");
			styleClass.Set("fill", "url(#xland2land)");
			svgImage->AddClass(styleClass);

			gradient = Svg::LinearGradient("xland2land");
			gradient.SetPath(0.42, 0, 0.58, 1);
			gradient.AddStop(Svg::GradientStop(0, Land::GetSurfaceColor()));
			gradient.AddStop(Svg::GradientStop(0.3, Land::GetSurfaceColor().Darken(0.1)));
			gradient.AddStop(Svg::GradientStop(0.8, Svg::Color(173, 124, 86)));
			svgImage->AddGradient(gradient);

			styleClass = Svg::StyleClass(".land.y.land2land");
			styleClass.Set("fill", "url(#yland2land)");
			svgImage->AddClass(styleClass);

			gradient = Svg::LinearGradient("yland2land");
			gradient.SetPath(0.6, 0, 0.4, 1);
			gradient.AddStop(Svg::GradientStop(0, Land::GetSurfaceColor()));
			gradient.AddStop(Svg::GradientStop(0.3, Land::GetSurfaceColor().Lighten(0.1)));
			gradient.AddStop(Svg::GradientStop(0.8, Svg::Color(173, 124, 86)));
			svgImage->AddGradient(gradient);

			//Land 2 Sand
			styleClass = Svg::StyleClass(".land.x.land2sand");
			styleClass.Set("fill", "url(#xland2sand)");
			svgImage->AddClass(styleClass);

			gradient = Svg::LinearGradient("xland2sand");
			gradient.SetPath(0.42, 0, 0.58, 1);
			gradient.AddStop(Svg::GradientStop(0, Land::GetSurfaceColor()));
			gradient.AddStop(Svg::GradientStop(0.3, Land::GetSurfaceColor()));
			gradient.AddStop(Svg::GradientStop(0.8, Svg::Color(255, 200, 0)));
			svgImage->AddGradient(gradient);

			styleClass = Svg::StyleClass(".land.y.land2sand");
			styleClass.Set("fill", "url(#yland2sand)");
			svgImage->AddClass(styleClass);

			gradient = Svg::LinearGradient("yland2sand");
			gradient.SetPath(0.6, 0, 0.4, 1);
			gradient.AddStop(Svg::GradientStop(0, Land::GetSurfaceColor()));
			gradient.AddStop(Svg::GradientStop(0.3, Land::GetSurfaceColor()));
			gradient.AddStop(Svg::GradientStop(0.8, Svg::Color(255, 200, 0)));
			svgImage->AddGradient(gradient);
		}
	}
};