/**
 * @file svg.h
 * @author  Adam Jędrzejowski <a.jedrzejowski@gmail.com>
 * @version 1.0
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
 * Plik z nagłówkowy klasy Svg
 */

#pragma once
#include "header.h"

using namespace std;

/**
 * Klasa zajmująca się tylko kreacją pliku SVG
 * Nic innego poza tym nie robi
 */
class Svg {
private:
	stringstream *output;//<! Stream z tekstem do wyjścia do pliku
public:
	int Height, //<! Wysokość obrazu
		Width; //<! Szerokość obrazu
public:
	/**
	 * Konstruktor klasy
	 * @param w szerokość obrazu
	 * @param h wysokość obrazu
	 */
	Svg(int w, int h);

	/**
     * Funkcja zapisująca do pliku
	 * @param path Scieżka do pliku wyjściowego
	 */
	void save(string path);

	/**
	 * Funkcja dodająca wielokąt do obrazu
	 * @param point1 pierwszy punkt wielokątu
	 * @param point2 drugi punkt wielokątu
	 * @param point3 trzeci punkt wielokątu
	 * @param point4 czwarty punkt wielokątu
	 */
	void addPolygon(Point point1, Point point2, Point point3, Point point4, string color);
};
