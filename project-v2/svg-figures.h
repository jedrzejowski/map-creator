/**
 * @file svg-figure.h
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
 * Plik z nagłówkowy klasy Svg:Figure i jej pochodnych
 */

#pragma once
#include "header.h"

namespace Svg {

	/**
	 * Klasa Figure dla sztuki
	 */
	class Figure {

	};

	/**
	 * Klasa reprezujenująca obiekt <polygon />
	 */
	class Polygon : public Figure {

		std::string Fill; //<! Wypełnienie
		vector<std::string> Clases; //<! Klasy Css
		vector<Point> Points; //<! Punkty składowe
	public:

		/**
		 * Wyczyszczenie zawartości obiektu, resetuje go
		 */
		void Clear();

		/**
		 * Dodaje nowy punkt do obiektu
		 * @param point
		 */
		void AddPoint(Point point);

		/**
		 * Dodje nową klase
		 * @param val
		 */
		void AddClass(std::string val);

		void SetFill(std::string val);
		std::string GetFill();

		/**
		 * Zwraca obiekt w postaci SVG <polygon ... />
		 * @return 
		 */
		std::string ToString();
	};
};
