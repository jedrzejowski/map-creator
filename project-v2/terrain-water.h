#pragma once
#include "terrain.h"

namespace Terrain {
	class Water : public Base {
	public:
		Water() {};
		Water(Base* terrain);

		virtual Svg::Color GetSurfaceColor();
		virtual Svg::Color GetWaterColor();

		virtual std::string GetWaterClasses();
		virtual std::string GetSurfaceClasses();
		virtual std::string GetName();

		virtual void InsertDefs(Svg::SvgImage* svgImage);
		virtual void DrawOn(Svg::SvgImage* scgImage);
	};
}

#include "terrain-deep.h"