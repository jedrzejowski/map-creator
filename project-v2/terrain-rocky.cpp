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
		return "x";
	}

	std::string Rocky::GetSurfaceYClasses() {
		return "y";
	}
	
	std::string Rocky::GetName() {
		return "rocky";
	}

	void Rocky::InsertDefs(Svg::SvgImage* svgImage) {
		static bool inserted = false;
		if (inserted) return;
		inserted = true;

		Svg::StyleClass styleClass;

		styleClass = Svg::StyleClass(".rocky");
		styleClass.Set("fill", Rocky::GetSurfaceColor().ToString());
		styleClass.Set("stroke", "dimgray");
		svgImage->AddClass(styleClass);

		styleClass = Svg::StyleClass(".rocky.x");
		styleClass.Set("fill", Rocky::GetSurfaceColor().Darken(0.1).ToString());
		svgImage->AddClass(styleClass);

		styleClass = Svg::StyleClass(".rocky.y");
		styleClass.Set("fill", Rocky::GetSurfaceColor().Lighten(0.1).ToString());
		svgImage->AddClass(styleClass);

		if (Settings::SmoothTerrainCross()) {
			Svg::LinearGradient gradient;

			//Rocky 2 Land
			styleClass = Svg::StyleClass(".rocky.x.rocky2land");
			styleClass.Set("fill", "url(#x-rocky2land)");
			svgImage->AddClass(styleClass);

			gradient = Svg::LinearGradient("x-rocky2land");
			gradient.SetPath(0.42, 0, 0.58, 1);
			gradient.AddStop(Svg::GradientStop(0, Rocky::GetSurfaceColor()));
			gradient.AddStop(Svg::GradientStop(0.3, Rocky::GetSurfaceColor().Darken(0.1)));
			gradient.AddStop(Svg::GradientStop(0.8, Svg::Color(126, 184, 88)));
			svgImage->AddGradient(gradient);

			styleClass = Svg::StyleClass(".rocky.y.rocky2land");
			styleClass.Set("fill", "url(#y-rocky2land)");
			svgImage->AddClass(styleClass);

			gradient = Svg::LinearGradient("y-rocky2land");
			gradient.SetPath(0.6, 0, 0.4, 1);
			gradient.AddStop(Svg::GradientStop(0, Rocky::GetSurfaceColor()));
			gradient.AddStop(Svg::GradientStop(0.3, Rocky::GetSurfaceColor().Lighten(0.1)));
			gradient.AddStop(Svg::GradientStop(0.8, Svg::Color(126, 184, 88)));
			svgImage->AddGradient(gradient);
		}

	}
};
