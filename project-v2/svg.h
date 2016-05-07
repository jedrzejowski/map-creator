#pragma once
#include "header.h"
#include "svg-figures.h"

using namespace std;

/**
* Klasa zajmuj�ca si� tylko kreacj� pliku SVG
* Nic innego poza tym nie robi
*/
class Svg {
private:
	stringstream *output;//<! Stream z tekstem do wyj�cia do pliku
public:
	int Height, //<! Wysoko�� obrazu
		Width; //<! Szeroko�� obrazu
public:
	/**
	* Konstruktor klasy
	* @param w szeroko�� obrazu
	* @param h wysoko�� obrazu
	*/
	Svg(int w, int h);

	/**
	* Funkcja zapisuj�ca do pliku
	* @param path Scie�ka do pliku wyj�ciowego
	*/
	void save(string path);

	/**
	* Funkcja dodaj�ca wielok�t do obrazu
	* @param point1 pierwszy punkt wielok�tu
	* @param point2 drugi punkt wielok�tu
	* @param point3 trzeci punkt wielok�tu
	* @param point4 czwarty punkt wielok�tu
	*/
	void addPolygon(Point point1, Point point2, Point point3, Point point4, string color);

	void addPolygon(Polygon& polygon);
};