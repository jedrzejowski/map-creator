#include "header.h"

namespace Terrain {
	Base::Base(int x, int y, int z) {
		SetX(x);
		SetY(y);
		SetZ(z);
	}

	void Base::Init() {

		if (GetZ() < 0)
			new Water(this);
		else
			new Land(this);
			
		//delete this;
	}

	int Base::GetX() { return X; }
	int Base::GetY() { return Y; }
	int Base::GetZ() { return Z; }
	void Base::SetX(int val) { X = val; }
	void Base::SetY(int val) { Y = val; }
	void Base::SetZ(int val) { 
		Z = val;
		Map::GetInstance().SetLowestPoint(Z);
	}

	void Base::InsertConstructor(Terrain::Base* base) {

		SetX(base->GetX());
		SetY(base->GetY());
		SetZ(base->GetZ());

		delete Map::GetInstance().GetTerrain(GetX(), GetY());
		Map::GetInstance().SetTerrain(GetX(), GetY(), this);

		//delete base;
	}

	void Base::DrawOn(Svg::SvgImage* svgImage) {
		Svg::Polygon polygon = Svg::Polygon();
		Terrain::Base* tempTer;

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
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY(), GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, tempTer->GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY(), tempTer->GetZ()));

			polygon.AddClass(GetSurfaceClasses());
			polygon.AddClass(GetSurfaceXClasses());

			svgImage->AddPolygon(polygon);
		}

		//Kraniec mapy na X 
		if(GetX() == Map::GetInstance().GetWidth() - 1){
			polygon.Clear();
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY(), GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, Map::GetInstance().GetLowestPoint()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY(), Map::GetInstance().GetLowestPoint()));

			polygon.AddClass(GetSurfaceClasses());
			polygon.AddClass(GetSurfaceXClasses());

			svgImage->AddPolygon(polygon);
		}

		//Klocek ni¿ej na Y
		tempTer = Map::GetInstance().GetTerrain(GetX(), GetY() + 1);
		if (tempTer->GetZ() < GetZ()) {
			polygon.Clear();
			polygon.AddPoint(Point::Transform(GetX(), GetY() + 1, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, tempTer->GetZ()));
			polygon.AddPoint(Point::Transform(GetX(), GetY() + 1, tempTer->GetZ()));

			polygon.AddClass(GetSurfaceClasses());
			polygon.AddClass(GetSurfaceYClasses());

			svgImage->AddPolygon(polygon);
		}

		//Kraniec mapy na Y
		if (GetY() == Map::GetInstance().GetLength() - 1) {

			polygon.Clear();
			polygon.AddPoint(Point::Transform(GetX(), GetY() + 1, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, GetZ()));
			polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, Map::GetInstance().GetLowestPoint()));
			polygon.AddPoint(Point::Transform(GetX(), GetY() + 1, Map::GetInstance().GetLowestPoint()));

			polygon.AddClass(GetSurfaceClasses());
			polygon.AddClass(GetSurfaceYClasses());

			svgImage->AddPolygon(polygon);
		}
	}
}