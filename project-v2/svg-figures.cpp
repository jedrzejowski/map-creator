#include "header.h"


void Polygon::Clear() {
	Points.clear();
	Fill = "red";
}

void Polygon::AddPoint(Point point) {
	Points.push_back(point);
}

int Polygon::Angles() {
	return Points.size();
}

string Polygon::FillColor() {
	return Fill;
}