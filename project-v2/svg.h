#pragma once
#include "header.h"
#include "svg-figures.h"

using namespace std;

/**
* Klasa zajmuj¹ca siê tylko kreacj¹ pliku SVG
* Nic innego poza tym nie robi
*/
class Svg {
private:
	stringstream *output;//<! Stream z tekstem do wyjœcia do pliku
public:
	int Height, //<! Wysokoœæ obrazu
		Width; //<! Szerokoœæ obrazu
public:
	/**
	* Konstruktor klasy
	* @param w szerokoœæ obrazu
	* @param h wysokoœæ obrazu
	*/
	Svg(int w, int h);

	/**
	* Funkcja zapisuj¹ca do pliku
	* @param path Scie¿ka do pliku wyjœciowego
	*/
	void save(string path);

	/**
	* Funkcja dodaj¹ca wielok¹t do obrazu
	* @param point1 pierwszy punkt wielok¹tu
	* @param point2 drugi punkt wielok¹tu
	* @param point3 trzeci punkt wielok¹tu
	* @param point4 czwarty punkt wielok¹tu
	*/
	void addPolygon(Point point1, Point point2, Point point3, Point point4, string color);

	void addPolygon(Polygon& polygon);
};