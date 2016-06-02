/**
 * @file svg-gradient.h
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
 * Plik z nagłówkowy klasy Svg::Gradient i jej pochodne
 */

#pragma once
#include "header.h"

namespace Svg {

	class GradientStop {
		private:
		float offset;
		Color color;

		public:
		GradientStop();
		GradientStop(float offset, Color color);

		void SetColor(Color color);
		Color GetColor();
		void SetOffset(float offset);
		float GetOffset();

		std::string ToString();
	};

	class LinearGradient {
		private:
		std::string Name;
		std::vector<GradientStop> Stops;
		float X1, Y1, X2, Y2;

		public:
		LinearGradient();
		LinearGradient(std::string name);

		void AddStop(GradientStop stop);
		void SetPath(float x1, float y1, float x2, float y2);

		std::string ToString();

		void SetName(std::string val);
		std::string GetName();
	};
};
