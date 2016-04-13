/**
 * @file point.cpp
 * @author  Adam Jędrzejowski <a.jedrzejowski@gmail.com>
 * @version 1.0
 *
 * @section LICENSE
 *
 * Copyright (C) 2016 Adam Jędrzejowski <a.jedrzejowski@gmail.com>
 * This file is part of map-creator
 *
 * map-creator can not be copied and/or distributed without the express
 * permission of Adam Jędrzejowski
 *
 * @section DESCRIPTION
 *
 * Plik z ciałami klasy Point
 */

#include "header.h"

using namespace std;

extern Map map;

Point::Point(int x, int y) {
	X = x;
	Y = y;
	Z = 0;
}

Point::Point(int x, int y, int z) {
	X = x;
	Y = y;
	Z = z;
}

double trans[][2] =
	{
		{ 0.6, -0.4 },
		{ 0.4, 0.6 }
	};

Point Point::Transform(int x, int y, int z) {
	x = 50 * x - map.Width * 50 / 2;
	y = 50 * y - map.Height * 50 / 2;

	x = x * trans[0][0] + y * trans[0][1];
	y = y * trans[1][1] + x * trans[1][0];

	x = x*1.8 + map.Width * 50;
	y = y + map.Height * 50 / 2;

	y = y - 5 * z;
	y = y + 5 * map.HighestPoint;

	return Point(x, y);
};
