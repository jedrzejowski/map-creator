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

Point::Point(float x, float y) {
	X = x;
	Y = y;
	Z = 0;
}

Point::Point(float x, float y, float z) {
	X = x;
	Y = y;
	Z = z;
}

double trans[][2] ={
	{ 0.6, -0.4 },
	{ 0.4, 0.6 }
};

Point Point::Transform(float x, float y, float z) {
	x = 50 * x - Settings::GetWidth() * 50 / 2;
	y = 50 * y - Settings::GetLength() * 50 / 2;

	x = x * trans[0][0] + y * trans[0][1];
	y = y * trans[1][1] + x * trans[1][0];

	x = x*1.8 + Settings::GetWidth() * 50;
	y = y + Settings::GetLength() * 50 / 2;

	y = y - 3 * z;
	//y = y + 3 * Settings::GetAmplitude() / 1.5;

	return Point(x, y);
};
