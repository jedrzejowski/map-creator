#pragma once
#include "terrain.h"

namespace Terrain {
	class Rocky : public Land {
	public:
		Rocky() { };
		Rocky(Land* terrain);

		virtual Svg::Color GetSurfaceColor();

		virtual std::string GetSurfaceClasses();
		virtual std::string GetName();

		virtual void InsertDefs(Svg::SvgImage* svgImage);
	};
}