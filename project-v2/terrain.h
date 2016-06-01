#pragma once
#include "header.h"

namespace Terrain
{
	/**
	 *
	 */
	class Base {
		int X, Y, Z;

	protected:
		/**
		 * [InsertConstructor description]
		 * @param base [description]
		 */
		void InsertConstructor(Base* base);

		/**
		 * [DrawWorldEdge description]
		 * @param svgImage [description]
		 */
		virtual void DrawWorldEdge(Svg::SvgImage* svgImage);

	public:
		/**
		 *
		 */
		Base() {};
		/**
		 *
		 */
		Base(int x, int y, int z);

		/**
		 * [Init description]
		 */
		virtual void Init();

		/**
		 * [GetX description]
		 * @return [description]
		 */
		int GetX();

		/**
		 * [GetY description]
		 * @return [description]
		 */
		int GetY();

		/**
		 * [GetZ description]
		 * @return [description]
		 */
		int GetZ();

		/**
		 * [SetX description]
		 * @param val [description]
		 */
		void SetX(int val);
		/**
		 * [SetY description]
		 * @param val [description]
		 */
		void SetY(int val);
		/**
		 * [SetZ description]
		 * @param val [description]
		 */
		void SetZ(int val);

		/**
		 * [GetTransitionNameX description]
		 * @return [description]
		 */
		std::string GetTransitionNameX();
		/**
		 * [GetTransitionNameY description]
		 * @return [description]
		 */
		std::string GetTransitionNameY();

		/**
		 * [GetSurfaceColor description]
		 * @return [description]
		 */
		virtual Svg::Color GetSurfaceColor() {};
		/**
		 * [GetSurfaceClasses description]
		 * @return [description]
		 */
		virtual std::string GetSurfaceClasses() {};
		/**
		 * [GetSurfaceXClasses description]
		 * @return [description]
		 */
		virtual std::string GetSurfaceXClasses();
		/**
		 * [GetSurfaceYClasses description]
		 * @return [description]
		 */
		virtual std::string GetSurfaceYClasses();
		/**
		 * [GetName description]
		 * @return [description]
		 */
		virtual std::string GetName() {};

		/**
		 * [InsertDefs description]
		 * @param svgImage [description]
		 */
		virtual void InsertDefs(Svg::SvgImage* svgImage) {};
		/**
		 * [DrawOn description]
		 * @param svgImage [description]
		 */
		virtual void DrawOn(Svg::SvgImage* svgImage);
	};
}

#include "terrain-land.h"
#include "terrain-water.h"
