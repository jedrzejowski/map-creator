#include "header.h"

using namespace std;

BaseTerrain::BaseTerrain() { }

BaseTerrain::BaseTerrain(int x, int y) {
	SetX(x);
	SetY(y);
	SetZ(0);
}

BaseTerrain::BaseTerrain(int x, int y, int z) {
	SetX(x);
	SetY(y);
	SetZ(z);
}

int BaseTerrain::GetX() { return X; }
int BaseTerrain::GetY() { return Y; }
int BaseTerrain::GetZ() { return Z; }
void BaseTerrain::SetX(int val) { X = val; }
void BaseTerrain::SetY(int val) { Y = val; }
void BaseTerrain::SetZ(int val) { Z = val; }

string BaseTerrain::GetSubsoil() { return "green"; }

void BaseTerrain::DrawOn(Svg* svgImage) {
	Polygon polygon = Polygon();
	BaseTerrain tempTer;

	//Podatawowy kloc terenu
	polygon.Clear();
	polygon.AddPoint(Point::Transform(GetX(), GetY(), GetZ()));
	polygon.AddPoint(Point::Transform(GetX(), GetY() + 1, GetZ()));
	polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, GetZ()));
	polygon.AddPoint(Point::Transform(GetX() + 1, GetY(), GetZ()));
	polygon.Fill = GetSubsoil();
	svgImage->addPolygon(polygon);

	//Klocek ni¿ej na X
	tempTer = Map::GetInstance().GetTerrain(GetX() + 1, GetY());
	if (tempTer.GetZ() < GetZ()) {
		polygon.Clear();
		polygon.AddPoint(Point::Transform(GetX() + 1, GetY(), GetZ()));
		polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, GetZ()));
		polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, tempTer.GetZ()));
		polygon.AddPoint(Point::Transform(GetX() + 1, GetY(), tempTer.GetZ()));
		polygon.Fill = GetSubsoil();
		svgImage->addPolygon(polygon);
	}

	//Klocek ni¿ej na Y
	tempTer = Map::GetInstance().GetTerrain(GetX(), GetY() + 1);
	if (tempTer.GetZ() < GetZ()) {
		polygon.Clear();
		polygon.AddPoint(Point::Transform(GetX(), GetY() + 1, GetZ()));
		polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, GetZ()));
		polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, tempTer.GetZ()));
		polygon.AddPoint(Point::Transform(GetX(), GetY() + 1, tempTer.GetZ()));
		polygon.Fill = GetSubsoil();
		svgImage->addPolygon(polygon);
	}
	
}