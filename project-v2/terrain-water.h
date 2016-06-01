/**
 * @file wtaer.cpp
 * @author  Adam Jędrzejowski <a.jedrzejowski@gmail.com>
 * @version 2.0
 *
 * @section LICENSE
 *
 * Copyright (C) 2016 Adam Jędrzejowski <a.jedrzejowski@gmail.com>
 * This file is part of map-creator
 *
 * map-creator can not be copied and/or distributed without the express
 * permission of Adam Jędrzejowski
 *
 * @section DESCRIPTION
 *
 * Plik z nagłówkami klasy Terrain::Water
 */

#pragma once
#include "terrain.h"

namespace Terrain {
	/**
	 * Klasa terenu reprezentująca tereny wodne, takie jak rzeki, jeziora i morza
	 */
	class Water : public Base {
	public:
		Water() {};
		Water(Base* terrain);

		virtual Svg::Color GetSurfaceColor();
		virtual Svg::Color GetWaterColor();
		virtual std::string GetWaterClasses();
		virtual std::string GetSurfaceClasses();
		virtual std::string GetName();

		virtual void InsertDefs(Svg::SvgImage* svgImage);
		virtual void DrawOn(Svg::SvgImage* scgImage);
	};
}

#include "terrain-deep.h"
