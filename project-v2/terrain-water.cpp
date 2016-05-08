#include "header.h"

WaterTerrain::WaterTerrain(BaseTerrain& base) {
	InsertConstructor(base);
	
	if (GetZ() < -(Map::GetInstance().GetAmplitude() / 4)) {
		new DeepTerrain(*this);
		return;
	}

}

Color WaterTerrain::GetBaseColor() {
	return Color(255,200,0); 
}

Color WaterTerrain::GetWaterColor() {
	return Color(173,216,230,0.75);
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