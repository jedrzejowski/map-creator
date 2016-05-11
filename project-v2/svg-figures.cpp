#include "header.h"

namespace Svg {
	void Polygon::Clear() {
		Points.clear();
		Clases.clear();
	}

	void Polygon::AddPoint(Point point) {
		Points.push_back(point);
	}

	void Polygon::AddClass(std::string val) {
		Clases.push_back(val);
	}

	int Polygon::Angles() {
		return Points.size();
	}
}