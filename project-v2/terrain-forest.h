#pragma once
#include "terrain.h"

#define FOREST_RANGE 4

namespace Terrain {
	class Forest : public Land {
	private:
		Forest(Base* terrain);
	public:
		Forest() { };
		Forest(Land* terrain);
		/**
		 * [TreeSeed description]
		 * @return [description]
		 */
		static bool TreeSeed();

		virtual std::string GetSurfaceClasses();

		virtual void DrawOn(Svg::SvgImage* svgImage);
		virtual void InsertDefs(Svg::SvgImage* svgImage);
	};
}
