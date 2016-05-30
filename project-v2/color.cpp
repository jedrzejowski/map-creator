/**
 * @file color.cpp
 * @author  Adam Jędrzejowski <a.jedrzejowski@gmail.com>
 * @version 2.0
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
 * Plik z ciałami klasy Svg::Color
 */

#include "header.h"

using namespace std;

namespace Svg {

	Color::Color() { }

	Color::Color(int r, int g, int b) {
		SetRed(r);
		SetGreen(g);
		SetBlue(b);
	}

	Color::Color(int r, int g, int b, float a) {
		SetRed(r);
		SetGreen(g);
		SetBlue(b);
		SetAlpha(a);
	}

	int Color::GetRed() { return Red; }
	int Color::GetGreen() { return Green; }
	int Color::GetBlue() { return Blue; }
	float Color::GetAlpha() { return Alpha; }

	void Color::SetRed(int val) {
		if (val > 255) {
			Red = 255;
			return;
		}

		if (val < 0) {
			Red = 0;
			return;
		}

		Red = val;
	}

	void Color::SetGreen(int val) {
		if (val > 255) {
			Green = 255;
			return;
		}

		if (val < 0) {
			Green = 0;
			return;
		}

		Green = val;
	}

	void Color::SetBlue(int val) {
		if (val > 255) {
			Blue = 255;
			return;
		}

		if (val < 0) {
			Blue = 0;
			return;
		}

		Blue = val;
	}

	void Color::SetAlpha(float val) {
		if (val > 1) {
			Alpha = 1;
			return;
		}

		if (val < 0) {
			Alpha = 0;
			return;
		}

		Alpha = val;
	}

	string Color::ToString() {
		std::stringstream out;

		out << "rgba(" << Red << "," << Green << "," << Blue << "," << Alpha << ")";

		return out.str();
	}

	Color Color::Darken(float value) {
		if (value > 1) value = 1;
		if (value < 0) value = 0;

		value = 1 - value;

		return Color(
			GetRed() * value,
			GetGreen() * value,
			GetBlue() * value,
			GetAlpha()
			);
	}

	Color Color::Lighten(float value) {
		if (value < 0) value = 0;

		value = 1 + value;

		return Color(
			GetRed() * value,
			GetGreen() * value,
			GetBlue() * value,
			GetAlpha()
			);
	}
}
