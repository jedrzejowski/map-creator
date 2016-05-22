#pragma once
#include "header.h"

namespace Terrain
{
	class Base {
		int X, Y, Z;

	protected:
		void InsertConstructor(Base* base);
		virtual void DrawWorldEdge(Svg::SvgImage* svgImage);

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

		std::string GetTransitionNameX();
		std::string GetTransitionNameY();

		virtual Svg::Color GetSurfaceColor() {};

		virtual std::string GetSurfaceClasses() {};
		virtual std::string GetSurfaceXClasses() {};
		virtual std::string GetSurfaceYClasses() {};
		virtual std::string GetName() {};

		
		virtual void InsertDefs(Svg::SvgImage* svgImage) {};
		virtual void DrawOn(Svg::SvgImage* svgImage);
	};
}
