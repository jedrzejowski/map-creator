#pragma once
#include "terrain.h"

namespace Terrain {
	class Sand : public Land {
	public:
		Sand() { };
		Sand(Land* terrain);

		virtual Svg::Color GetSurfaceColor();

		virtual std::string GetSurfaceClasses();
		virtual std::string GetSurfaceXClasses();
		virtual std::string GetSurfaceYClasses();
		virtual std::string GetName();

		virtual void InsertDefs(Svg::SvgImage* svgImage);
	};
};