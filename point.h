#pragma once
#include "header.h"

using namespace std;

class Point {
private:
public:
	int X, Y, Z;

	Point(int x, int y);
	Point(int x, int y, int z);
	static Point Transform(int x, int y);
	static Point Transform(int x, int y, int z);
};