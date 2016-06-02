/**
 * @file svg-figures.cpp
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
 * Plik z ciałami klasy Svg::Figure i jej pochodnych
 */

#include "header.h"

namespace Svg {
	void Polygon::Clear() {
		Points.clear();
		Clases.clear();
		Fill = "";
	}

	void Polygon::AddPoint(Point point) {
		Points.push_back(point);
	}

	void Polygon::AddClass(std::string val) {
		Clases.push_back(val);
	}

	void Polygon::SetFill(std::string val) {
		Fill = val;
	}

	std::string Polygon::GetFill() {
		return Fill;
	}

	std::string Polygon::ToString() {
		stringstream output;
		output << "<polygon";

		//fill
		if (Fill.length() > 0) {
			output << " fill='" << Fill << "'";
		}

		output << " points='";
		for (int i = 0, size = Points.size() - 1; i <= size; i++) {
			output << Points[i].X << "," << Points[i].Y;

			if (i != size)
				output << " ";
		}
		output << "'";

		//Klasy
		if (Clases.size() > 0) {
			output << " class='";
			for (int i = 0, size = Clases.size() - 1; i <= size; i++) {
				output << Clases[i];

				if (i != size)
					output << " ";
			}
			output << "'";
		}

		output << "/>";
		return output.str();
	}
}
