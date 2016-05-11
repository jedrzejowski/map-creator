#pragma once
#include "header.h"

namespace Svg {


	class Figure {

	};

	class Polygon : public Figure {
		friend class SvgImage;

		vector<std::string> Clases;
		vector<Point> Points;
	public:

		void Clear();

		void AddPoint(Point point);
		void AddClass(std::string val);

		int Angles();
	};
};