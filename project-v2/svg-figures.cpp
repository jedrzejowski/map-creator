#include "header.h"


void Polygon::Clear() {
	Points.clear();
}

void Polygon::AddPoint(Point point) {
	Points.push_back(point);
}

int Polygon::Angles() {
	return Points.size();
}

Color Polygon::FillColor() {
	return Fill;
}