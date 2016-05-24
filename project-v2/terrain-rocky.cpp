#include "header.h"

namespace Terrain {
	static PerlinNoise* perlinNoise;

	Rocky::Rocky(Land* base) {
		InsertConstructor(base);
	}

	void Rocky::Init() {
		if (perlinNoise == NULL) {
			perlinNoise = new PerlinNoise(
				Settings::GetPersistence(),
				Settings::GetFrequency(),
				Settings::GetAmplitude(),
				Settings::GetOctaves(),
				Settings::GetRandomseed()/2);
		}

		pattern = (int)perlinNoise->GetHeight(GetX(), GetY()) % ROCKY_COLOR_HUE;

		lake = rand() % 150 == 0 ? true : false;
	}

	Svg::Color Rocky::GetSurfaceColor() {
		return Svg::Color(200, 200, 200);
	}

	std::string Rocky::GetSurfaceClasses() {
		return "rocky pattern" + to_string(pattern);
	}
	
	std::string Rocky::GetName() {
		return "rocky";
	}

	void Rocky::InsertDefs(Svg::SvgImage* svgImage) {
		static bool inserted = false;
		if (inserted) return;
		inserted = true;

		Svg::StyleClass styleClass;

		styleClass = Svg::StyleClass::FillClass(".rocky", Rocky::GetSurfaceColor());
		styleClass.Set("stroke", "dimgray");
		svgImage->AddClass(styleClass);

		svgImage->AddClass(Svg::StyleClass::FillClass(".rocky.x", Rocky::GetSurfaceColor().Darken(0.1)));
		svgImage->AddClass(Svg::StyleClass::FillClass(".rocky.y", Rocky::GetSurfaceColor().Lighten(0.1)));


		//Style bazuj¹ce na mozaice
		stringstream stream;
		for (int i = 0; i < ROCKY_COLOR_HUE; i++ ) {
			Svg::Color pattern = Rocky::GetSurfaceColor().Darken(((float)i) * (1.0f / (ROCKY_COLOR_HUE + 80.0f)));
			std::string index = to_string(i);

			svgImage->AddClass(Svg::StyleClass::FillClass(
				".rocky.pattern" + index, pattern));

			svgImage->AddClass(Svg::StyleClass::FillClass(
				".rocky.x.pattern" + index, pattern.Darken(0.1)));

			svgImage->AddClass(Svg::StyleClass::FillClass(
				".rocky.y.pattern" + index, pattern.Lighten(0.1)));

			if (Settings::SmoothTerrainCross()) {
				Svg::LinearGradient gradient;

				//Rocky 2 Land
				svgImage->AddClass(Svg::StyleClass::FillClass(
					".rocky.x.rocky2land.pattern" + index, "url(#x-rocky2land-" + index + ")"));

				gradient = Svg::LinearGradient("x-rocky2land-" + to_string(i));
				gradient.SetPath(0.42, 0, 0.58, 1);
				gradient.AddStop(Svg::GradientStop(0, pattern));
				gradient.AddStop(Svg::GradientStop(0.3, pattern.Darken(0.1)));
				gradient.AddStop(Svg::GradientStop(0.8, Svg::Color(126, 184, 88)));
				svgImage->AddGradient(gradient);

				svgImage->AddClass(Svg::StyleClass::FillClass(
					".rocky.y.rocky2land.pattern" + index, "url(#y-rocky2land-" + index + ")"));

				gradient = Svg::LinearGradient("y-rocky2land-" + to_string(i));
				gradient.SetPath(0.6, 0, 0.4, 1);
				gradient.AddStop(Svg::GradientStop(0, pattern));
				gradient.AddStop(Svg::GradientStop(0.3, pattern.Lighten(0.1)));
				gradient.AddStop(Svg::GradientStop(0.8, Svg::Color(126, 184, 88)));
				svgImage->AddGradient(gradient);
			}
		}

		svgImage->AddClass(Svg::StyleClass::FillClass(
			".rocky.lake", Svg::Color(173, 216, 230)));

	}

	void Rocky::DrawOn(Svg::SvgImage* svgImage) {
		Land::DrawOn(svgImage);
		Svg::Polygon polygon = Svg::Polygon();

		if (lake) {

			polygon.Clear();
			polygon.AddPoint(Point::Transform(GetX() + 0.2, GetY() + 0.2, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 0.8, GetY() + 0.2, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 0.8, GetY() + 0.8, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 0.2, GetY() + 0.8, GetZ()));
			polygon.AddClass(Rocky::GetSurfaceClasses());
			svgImage->AddPolygon(polygon);

			polygon.Clear();
			polygon.AddPoint(Point::Transform(GetX() + 0.3, GetY() + 0.3, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 0.8, GetY() + 0.3, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 0.8, GetY() + 0.8, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 0.3, GetY() + 0.8, GetZ()));
			polygon.AddClass(Rocky::GetSurfaceClasses());
			polygon.AddClass("lake");
			svgImage->AddPolygon(polygon);

		}
	}
};
