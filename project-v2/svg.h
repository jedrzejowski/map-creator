#pragma once
#include "header.h"
#include "color.h"
#include "point.h"
#include "svg-figures.h"
#include "svg-style.h"
#include "svg-gradient.h"
#include "svg-text.h"

namespace Svg {
	/**
	* Klasa zajmuj�ca si� tylko kreacj� pliku SVG
	* Nic innego poza tym nie robi
	*/
	class SvgImage {
	private:
		string content;//<! Stream z tekstem do wyj�cia do pliku
		int Height, //<! Wysoko�� obrazu
			Width; //<! Szeroko�� obrazu

		std::vector<StyleClass> styleClasses;
		std::vector<LinearGradient> linearGradients;

	public:
		/**
		* Konstruktor klasy
		* @param w szeroko�� obrazu
		* @param h wysoko�� obrazu
		*/
		SvgImage(int w, int h);

		/**
		* Funkcja zapisuj�ca do pliku
		* @param path Scie�ka do pliku wyj�ciowego
		*/
		void Save(std::string path);

		void AddClass(StyleClass classProps);
		void AddGradient(LinearGradient gradient);


		void AddPolygon(Polygon polygon);
		void AddRaw(std::string content);
		void AddText(Text text);
	};
};