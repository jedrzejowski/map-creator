#pragma once
#include "header.h"

namespace Terrain {
	class Rocky : public Land {
	public:
		Rocky() { };
		Rocky(Land* terrain);

		virtual Svg::Color GetSurfaceColor();

		virtual std::string GetSurfaceClasses();
		virtual std::string GetSurfaceXClasses();
		virtual std::string GetSurfaceYClasses();
		virtual std::string GetName();

		virtual void InsertDefs(Svg::SvgImage* svgImage);
	};
}