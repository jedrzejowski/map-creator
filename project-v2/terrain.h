/**
 * @file terrain.h
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
 * Plik z nagłówkowy klasy Terrain::Base
 */

#pragma once
#include "header.h"

namespace Terrain
{
	/**
	 * Podstawowa klasa terenu
	 */
	class Base {
		int X, //<! Współrzędna X
			Y, //<! Współrzędna Y
			Z;  //<! wysokość

	protected:
		/**
		 * Jest to funckja która powinna być wykonana gdy chcemy obiekt włożyć do tbalicy surface Mapy.
		 * Usuwa ona poprzedni element i wstawia nowy
		 * @param base nowy teren
		 */
		void InsertConstructor(Base* base);

		/**
		 * Rysuje krawdescription]ędzie mapy
		 * @param svgImage wskaźnik do rysunku Svg::SvgImage
		 */
		virtual void DrawWorldEdge(Svg::SvgImage* svgImage);

	public:
		/**
		 * Konstukktor domyślny
		 */
		Base() {};

		/**
		 * Konstruktor z współrzędnymi
		 * @param x X
		 * @param y Y
		 * @param z Z, wysokość
		 */
		Base(int x, int y, int z);

		/**
		 * Inicjuje obiekt, obiekt sprawdza swoje otoczenie i odnanduje sam siebie
		 */
		virtual void Init();

		int GetX();
		int GetY();
		int GetZ();
		void SetX(int val);
		void SetY(int val);
		void SetZ(int val);
//<! Współrzędna X
		/**
		 * Zwaraca nazwe klasy przejścia między terenowego na X, uwzględnia sąsiadów
		 * @return
		 */
		std::string GetTransitionNameX();

		/**
		 * Zwaraca nazwe klasy przejścia między terenowego na Y, uwzględnia sąsiadów
		 * @return
		 */
		std::string GetTransitionNameY();

		/**
		 * Zwraca kolor powierzcni
		 * @return
		 */
		virtual Svg::Color GetSurfaceColor() {};

		/**
		 * Zwraca klase/klasy powierzchni
		 * @return
		 */
		virtual std::string GetSurfaceClasses() {};

		/**
		 * Zwraca klase/klasy przejścia terenowego na X
		 * @return
		 */
		virtual std::string GetSurfaceXClasses();

		/**
		 * Zwraca klase/klasy przejścia terenowego na Y
		 * @return
		 */
		virtual std::string GetSurfaceYClasses();

		/**
		 * Zwraca nazwe terenu
		 * @return
		 */
		virtual std::string GetName() {};

		/**
		 * Dodaje definicja swoich zasobów do obrazu Svg::SvgImage
		 * @param svgImage
		 */
		virtual void InsertDefs(Svg::SvgImage* svgImage) {};

		/**
		 * Rysuje samego siebie na obrazie
		 * @param svgImage
		 */
		virtual void DrawOn(Svg::SvgImage* svgImage);
	};
}

#include "terrain-land.h"
#include "terrain-water.h"
