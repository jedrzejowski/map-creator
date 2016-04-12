#include "header.h"

using namespace std;

Svg::Svg() {
}


Svg::Svg(int w, int h) {
	Width = w;
	Height = h;
}

void Svg::save(string path) {
	FILE * file = fopen(path.c_str(), "w");

	fprintf(file, "<svg xmlns='http://www.w3.org/2000/svg' width='%d' height='%d'>%s</svg>", 
		Width, Height, output->str().c_str());

	fclose(file);
};

void Svg::addRectangle(int x, int y, int w, int h, string color) {
	*output << "<rect x='" << x << "' y='" << y << "' width='" << w << "' height='" << h << "' style='fill:" << color << ";' />";
};

void Svg::addPolygon(Point point1, Point point2, Point point3, Point point4, string color) {
	*output << "<polygon points='"
		<< point1.X << "," << point1.Y << " "
		<< point2.X << "," << point2.Y << " "
		<< point3.X << "," << point3.Y << " "
		<< point4.X << "," << point4.Y << "' "
		<< "style='fill:" << color << ";stroke:white;stroke-width:0.3' />";
};