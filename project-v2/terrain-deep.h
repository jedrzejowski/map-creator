#pragma once
#include "terrain.h"

namespace Terrain {
	class Deep : public Water {
	public:
		Deep(Water* terrain);

		virtual Svg::Color GetWaterColor();
		virtual std::string GetWaterClasses();
		virtual std::string GetName();

		virtual void InsertDefs(Svg::SvgImage* svgImage);
	};
}