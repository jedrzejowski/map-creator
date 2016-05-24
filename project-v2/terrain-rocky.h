#pragma once
#include "terrain.h"

#define ROCKY_COLOR_LIB_LENGTH 15

namespace Terrain {

	class Rocky : public Land {
	private:
		int pattern = -1;
		bool lake = false;
	public:
		Rocky() { };
		Rocky(Land* terrain);

		virtual Svg::Color GetSurfaceColor();

		virtual std::string GetSurfaceClasses();
		virtual std::string GetName();
		virtual void Init();

		virtual void InsertDefs(Svg::SvgImage* svgImage);
		virtual void DrawOn(Svg::SvgImage* svgImage);
	};
}