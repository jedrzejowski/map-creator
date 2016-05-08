#include "header.h"

WaterTerrain::WaterTerrain(BaseTerrain& base) {
	InsertConstructor(base);
	
	if (GetZ() < -(Map::GetInstance().GetAmplitude() / 4)) {
		new DeepTerrain(*this);
		return;
	}

}

string WaterTerrain::GetSubsoil() { 
	return "goldenrod"; 
}

string WaterTerrain::GetWaterColor() {
	return "rgba(173,216,230,0.75)";
}

void WaterTerrain::DrawOn(Svg* svgImage) {
	BaseTerrain::DrawOn(svgImage);

	Polygon polygon;

	polygon.Clear();
	polygon.AddPoint(Point::Transform(GetX(), GetY()));
	polygon.AddPoint(Point::Transform(GetX(), GetY() + 1));
	polygon.AddPoint(Point::Transform(GetX() + 1, GetY() + 1));
	polygon.AddPoint(Point::Transform(GetX() + 1, GetY()));
	polygon.Fill = GetWaterColor();

	svgImage->addPolygon(polygon);

}