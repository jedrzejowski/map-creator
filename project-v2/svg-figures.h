#pragma once
#include "header.h"

class Figure {

};

class Polygon : public Figure {
public:
	vector<Point> Points;
	string Fill;

	void Clear();

	void AddPoint(Point point);

	int Angles();
	string FillColor();

};