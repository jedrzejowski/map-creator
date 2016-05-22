#pragma once
#include "header.h"

namespace Svg {


	class Figure {

	};

	class Polygon : public Figure {
		//friend class SvgImage;

		std::string Fill;
		vector<std::string> Clases;
		vector<Point> Points;
	public:

		void Clear();

		void AddPoint(Point point);
		void AddClass(std::string val);

		void SetFill(std::string val);
		std::string GetFill();

		std::string ToString();
	};
};