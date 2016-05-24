#pragma once
#include "terrain.h"

#define SAND_WATER_DISTANCE 4

namespace Terrain {
	class Sand : public Land {
	private:
		int dist2Water = SAND_WATER_DISTANCE;

	public:
		Sand() { };
		Sand(Land* terrain);

		virtual void Init();

		virtual Svg::Color GetSurfaceColor();

		virtual std::string GetSurfaceClasses();
		virtual std::string GetName();

		virtual void InsertDefs(Svg::SvgImage* svgImage);
	};
};