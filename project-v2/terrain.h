#pragma once
#include "header.h"

namespace Terrain
{
	class Base {
		int X, Y, Z;

	protected:
		void InsertConstructor(Base* base);

	public:
		Base() {};
		Base(int x, int y, int z);

		void Init();

		int GetX();
		int GetY();
		int GetZ();

		void SetX(int val);
		void SetY(int val);
		void SetZ(int val);

		virtual Svg::Color GetSurfaceColor() {};

		virtual std::string GetSurfaceClasses() {};
		virtual std::string GetSurfaceXClasses() {};
		virtual std::string GetSurfaceYClasses() {};

		
		virtual void InsertStyle(Svg::SvgImage* svgImage) {};
		virtual void DrawOn(Svg::SvgImage* svgImage);
	};
}
