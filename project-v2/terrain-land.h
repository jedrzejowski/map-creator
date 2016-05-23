#pragma once
#include "terrain.h"

namespace Terrain {
	class Land : public Base {
	public:
		Land() { };
		Land(Base* terrain);

		virtual Svg::Color GetSurfaceColor();

		virtual std::string GetSurfaceClasses();
		virtual std::string GetName();
		virtual void Init();

		virtual void InsertDefs(Svg::SvgImage* svgImage);
	};
};

#include "terrain-rocky.h"
#include "terrain-sand.h"
#include "terrain-forest.h"