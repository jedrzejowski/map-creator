#pragma once
#include "header.h"

namespace Terrain {
	class Sand : public Land {
	public:
		Sand() { };
		Sand(Land* terrain);

		virtual Svg::Color GetSurfaceColor();

		virtual std::string GetSurfaceClasses();
		virtual std::string GetSurfaceXClasses();
		virtual std::string GetSurfaceYClasses();

		virtual void InsertStyle(Svg::SvgImage* svgImage);
	};
};