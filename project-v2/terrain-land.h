#pragma once
#include "header.h"

namespace Terrain {
	class Land : public Base {
	public:
		Land() { };
		Land(Base* terrain);

		virtual Svg::Color GetSurfaceColor();

		virtual std::string GetSurfaceClasses();
		virtual std::string GetSurfaceXClasses();
		virtual std::string GetSurfaceYClasses();
		virtual std::string GetName();

		virtual void InsertDefs(Svg::SvgImage* svgImage);
	};
};