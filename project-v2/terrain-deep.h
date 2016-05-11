#pragma once
#include "header.h"

namespace Terrain {
	class Deep : public Water {
	public:
		Deep(Water* terrain);

		virtual Svg::Color GetWaterColor();
		virtual std::string GetWaterClasses();

		virtual void InsertStyle(Svg::SvgImage* svgImage);
	};
}