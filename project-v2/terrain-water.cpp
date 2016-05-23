#include "header.h"

namespace Terrain {

	Water::Water(Base* base) {
		InsertConstructor(base);

		if (GetZ() < -(Settings::GetAmplitude() / 4)) {
			new Deep(this);
		}

	}

	Svg::Color Water::GetSurfaceColor() {
		return Svg::Color(255, 200, 0);
	}

	Svg::Color Water::GetWaterColor() {
		return Svg::Color(173, 216, 230, 0.75);
	}

	std::string Water::GetWaterClasses() {
		return "water";
	}

	std::string Water::GetSurfaceClasses() {
		return "water-bottom";
	}

	std::string Water::GetName() {
		return "water";
	}

	void Water::InsertDefs(Svg::SvgImage* svgImage) {
		static bool inserted = false;

		if (inserted) return;
		inserted = true;

		Svg::StyleClass styleClass;

		styleClass = Svg::StyleClass(".water");
		styleClass.Set("fill", Water::GetWaterColor().ToString());
		svgImage->AddClass(styleClass);

		styleClass = Svg::StyleClass(".water-bottom");
		styleClass.Set("fill", Water::GetSurfaceColor().ToString());
		svgImage->AddClass(styleClass);

		styleClass = Svg::StyleClass(".water-bottom.x");
		styleClass.Set("fill", Water::GetSurfaceColor().Darken(0.1).ToString());
		svgImage->AddClass(styleClass);

		styleClass = Svg::StyleClass(".water-bottom.y");
		styleClass.Set("fill", Water::GetSurfaceColor().Lighten(0.1).ToString());
		svgImage->AddClass(styleClass);
	}

	void Water::DrawOn(Svg::SvgImage* svgImage) {

		// W Przypadku niskiej grafiki nie wysuje dna wodnego
		if (Settings::IsLowGraphic()) {
			DrawWorldEdge(svgImage);
		} else {
			Terrain::Base::DrawOn(svgImage);
		}

		Svg::Polygon polygon;

		polygon.Clear();
		polygon.AddPoint(Point::Transform(GetX(), GetY()));
		polygon.AddPoint(Point::Transform(GetX(), GetY() + 1));
		polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1));
		polygon.AddPoint(Point::Transform(GetX() + 1, GetY()));

		polygon.AddClass(GetWaterClasses());

		svgImage->AddPolygon(polygon);

		//Kraniec mapy na X 
		if (GetX() == Settings::GetWidth() - 1) {
			polygon.Clear();
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY(), 0));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, 0));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY(), GetZ()));

			polygon.AddClass(GetWaterClasses());

			svgImage->AddPolygon(polygon);
		}

		//Kraniec mapy na Y
		if (GetY() == Settings::GetLength() - 1) {

			polygon.Clear();
			polygon.AddPoint(Point::Transform(GetX(), GetY() + 1, 0));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, 0));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, GetZ()));
			polygon.AddPoint(Point::Transform(GetX(), GetY() + 1, GetZ()));

			polygon.AddClass(GetWaterClasses());

			svgImage->AddPolygon(polygon);
		}
	}
}