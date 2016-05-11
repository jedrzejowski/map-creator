#pragma once
#include "header.h"
#include "color.h"
#include "point.h"
#include "svg-figures.h"
#include "svg-style.h"

namespace Svg {
	/**
	* Klasa zajmuj¹ca siê tylko kreacj¹ pliku SVG
	* Nic innego poza tym nie robi
	*/
	class SvgImage {
	private:
		stringstream *content, *styles;//<! Stream z tekstem do wyjœcia do pliku
		int Height, //<! Wysokoœæ obrazu
			Width; //<! Szerokoœæ obrazu

		std::vector<StyleClass> styleClasses;

		void GenerateStyles();
	public:
		/**
		* Konstruktor klasy
		* @param w szerokoœæ obrazu
		* @param h wysokoœæ obrazu
		*/
		SvgImage(int w, int h);

		/**
		* Funkcja zapisuj¹ca do pliku
		* @param path Scie¿ka do pliku wyjœciowego
		*/
		void save(std::string path);

		void AddClass(StyleClass classProps);


		void AddPolygon(Polygon& polygon);
	};
};