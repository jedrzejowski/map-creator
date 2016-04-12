#pragma once
#include "header.h"

using namespace std;

class Svg {
private:
	stringstream *output;
public:
	int Height, Width;
public:
	Svg();
	Svg(int w, int h);
	void save(string path);

	void addRectangle(int x, int y, int w, int h, string color);

	void addPolygon(Point point1, Point point2, Point point3, Point point4, string color);
};