#include "header.h"

namespace Terrain {
	Base::Base(int x, int y, int z) {
		SetX(x);
		SetY(y);
		SetZ(z);

		if (GetZ() < 0)
			new Water(this);
		else
			new Land(this);
	}

	void Base::Init() {
		
	}

	int Base::GetX() { return X; }
	int Base::GetY() { return Y; }
	int Base::GetZ() { return Z; }
	void Base::SetX(int val) { X = val; }
	void Base::SetY(int val) { Y = val; }
	void Base::SetZ(int val) { 
		Z = val;
		Settings::SetLowestPoint(Z);
	}

	std::string Base::GetSurfaceXClasses() {
		return "x";
	}

	std::string Base::GetSurfaceYClasses() {
		return "y";
	}

	std::string Base::GetTransitionNameX() {
		stringstream out;
		out << GetName() << "2" << Map::GetTerrain(GetX() + 1, GetY())->GetName();
		return out.str();
	}

	std::string Base::GetTransitionNameY() {
		stringstream out;
		out << GetName() << "2" << Map::GetTerrain(GetX(), GetY() + 1)->GetName();
		return out.str();
	}

	void Base::InsertConstructor(Terrain::Base* base) {

		SetX(base->GetX());
		SetY(base->GetY());
		SetZ(base->GetZ());

		delete Map::GetTerrain(GetX(), GetY());
		Map::SetTerrain(GetX(), GetY(), this);

		//delete base;
	}

	void Base::DrawOn(Svg::SvgImage* svgImage) {
		Svg::Polygon polygon = Svg::Polygon();
		Terrain::Base* tempTer;
		int tempZ;

		//Podatawowy kloc terenu
		polygon.Clear();
		polygon.AddPoint(Point::Transform(GetX(), GetY(), GetZ()));
		polygon.AddPoint(Point::Transform(GetX(), GetY() + 1, GetZ()));
		polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, GetZ()));
		polygon.AddPoint(Point::Transform(GetX() + 1, GetY(), GetZ()));

		polygon.AddClass(GetSurfaceClasses());

		svgImage->AddPolygon(polygon);

		//Klocek ni¿ej na X
		tempTer = Map::GetInstance().GetTerrain(GetX() + 1, GetY());
		if (tempTer->GetZ() < GetZ()) {
			polygon.Clear();

			tempZ = tempTer->GetZ();
			if (tempZ < 0) if (Settings::IsLowGraphic()) tempZ = 0;

			polygon.AddPoint(Point::Transform(GetX() + 1, GetY(), GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, tempZ));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY(), tempZ));

			polygon.AddClass(GetSurfaceClasses());
			polygon.AddClass(GetSurfaceXClasses());
			polygon.AddClass(GetTransitionNameX());

			svgImage->AddPolygon(polygon);
		}

		//Klocek ni¿ej na Y
		tempTer = Map::GetInstance().GetTerrain(GetX(), GetY() + 1);
		if (tempTer->GetZ() < GetZ()) {
			polygon.Clear();

			tempZ = tempTer->GetZ();
			if (tempZ < 0) if (Settings::IsLowGraphic()) tempZ = 0;

			polygon.AddPoint(Point::Transform(GetX(), GetY() + 1, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, tempZ));
			polygon.AddPoint(Point::Transform(GetX(), GetY() + 1, tempZ));

			polygon.AddClass(GetSurfaceClasses());
			polygon.AddClass(GetSurfaceYClasses());
			polygon.AddClass(GetTransitionNameY());

			svgImage->AddPolygon(polygon);
		}
		
		DrawWorldEdge(svgImage);
	}

	void Base::DrawWorldEdge(Svg::SvgImage* svgImage) {
		Svg::Polygon polygon = Svg::Polygon();
		Terrain::Base* tempTer;
		int tempZ;

		//Kraniec mapy na X 
		if (GetX() == Settings::GetWidth() - 1) {
			polygon.Clear();

			polygon.AddPoint(Point::Transform(GetX() + 1, GetY(), GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, Settings::GetLowestPoint()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY(), Settings::GetLowestPoint()));

			polygon.AddClass(GetSurfaceClasses());
			polygon.AddClass(GetSurfaceXClasses());
			polygon.AddClass(GetTransitionNameX());

			svgImage->AddPolygon(polygon);
		}

		//Kraniec mapy na Y
		if (GetY() == Settings::GetLength() - 1) {
			polygon.Clear();

			polygon.AddPoint(Point::Transform(GetX(), GetY() + 1, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, Settings::GetLowestPoint()));
			polygon.AddPoint(Point::Transform(GetX(), GetY() + 1, Settings::GetLowestPoint()));

			polygon.AddClass(GetSurfaceClasses());
			polygon.AddClass(GetSurfaceYClasses());
			polygon.AddClass(GetTransitionNameY());

			svgImage->AddPolygon(polygon);
		}
	}
}