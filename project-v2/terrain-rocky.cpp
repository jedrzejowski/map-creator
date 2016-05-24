#include "header.h"

namespace Terrain {

	Rocky::Rocky(Land* base) {
		InsertConstructor(base);
	}

	void Rocky::Init() {

		pattern = rand() % ROCKY_COLOR_LIB_LENGTH;

		if (Map::GetTerrain(GetX() + 1, GetY())->GetZ() > GetZ())
			pattern += ROCKY_COLOR_LIB_LENGTH / 5;

		if (Map::GetTerrain(GetX() + 1, GetY())->GetZ() < GetZ())
			pattern -= ROCKY_COLOR_LIB_LENGTH / 5;

		if (pattern < 0)pattern = 0;
		if (pattern >= ROCKY_COLOR_LIB_LENGTH)pattern = ROCKY_COLOR_LIB_LENGTH - 1;

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

		stringstream stream;
		for (int i = 0; i < ROCKY_COLOR_LIB_LENGTH; i++ ) {
			Svg::Color color = Rocky::GetSurfaceColor().Darken(((float)i) * (1.0f / (ROCKY_COLOR_LIB_LENGTH + 40.0f)));
		
			styleClass = Svg::StyleClass(".rocky.pattern" + to_string(i));
			styleClass.Set("fill", color.ToString());
			styleClass.Set("stroke", "dimgray");
			svgImage->AddClass(styleClass);

			styleClass = Svg::StyleClass(".rocky.x.pattern" + to_string(i));
			styleClass.Set("fill", color.Darken(0.1).ToString());
			svgImage->AddClass(styleClass);

			styleClass = Svg::StyleClass(".rocky.y.patern" + to_string(i));
			styleClass.Set("fill", color.Lighten(0.1).ToString());
			svgImage->AddClass(styleClass);
		}

		styleClass = Svg::StyleClass(".rocky.lake");
		styleClass.Set("fill", Svg::Color(173, 216, 230).ToString());
		svgImage->AddClass(styleClass);

		

		/*if (Settings::SmoothTerrainCross()) {
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
		}*/

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
