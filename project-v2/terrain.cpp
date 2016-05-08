#include "header.h"

using namespace std;

BaseTerrain::BaseTerrain() { }

BaseTerrain::BaseTerrain(int x, int y, int z) {
	SetX(x);
	SetY(y);
	SetZ(z);
}

void BaseTerrain::Init(){

	if (GetZ() < 0) 
		new WaterTerrain(*this);
	else
		new LandTerrain(*this);

	//delete this;
}

int BaseTerrain::GetX() { return X; }
int BaseTerrain::GetY() { return Y; }
int BaseTerrain::GetZ() { return Z; }
void BaseTerrain::SetX(int val) { X = val; }
void BaseTerrain::SetY(int val) { Y = val; }
void BaseTerrain::SetZ(int val) { Z = val; }

string BaseTerrain::GetSubsoil() { 
	return "black";
}

template <typename T>
bool BaseTerrain::is(T className) {
	return typeid(*this).name() == typeid(className).name();
}

void BaseTerrain::InsertConstructor(BaseTerrain& base) {

	SetX(base.GetX());
	SetY(base.GetY());
	SetZ(base.GetZ());

	delete Map::GetInstance().GetTerrain(GetX(), GetY());
	Map::GetInstance().SetTerrain(GetX(), GetY(), this);
}

void BaseTerrain::DrawOn(Svg* svgImage) {
	Polygon polygon = Polygon();
	BaseTerrain* tempTer;

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
	if (tempTer->GetZ() < GetZ()) {
		polygon.Clear();
		polygon.AddPoint(Point::Transform(GetX() + 1, GetY(), GetZ()));
		polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, GetZ()));
		polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, tempTer->GetZ()));
		polygon.AddPoint(Point::Transform(GetX() + 1, GetY(), tempTer->GetZ()));
		polygon.Fill = GetSubsoil();
		svgImage->addPolygon(polygon);
	}

	//Klocek ni¿ej na Y
	tempTer = Map::GetInstance().GetTerrain(GetX(), GetY() + 1);
	if (tempTer->GetZ() < GetZ()) {
		polygon.Clear();
		polygon.AddPoint(Point::Transform(GetX(), GetY() + 1, GetZ()));
		polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, GetZ()));
		polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1, tempTer->GetZ()));
		polygon.AddPoint(Point::Transform(GetX(), GetY() + 1, tempTer->GetZ()));
		polygon.Fill = GetSubsoil();
		svgImage->addPolygon(polygon);
	}
	
}