/**
 * @file point.h
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
 * Plik z nagłówkowy klasy Point
 */

#pragma once
#include "header.h"

using namespace std;

/**
 * Funkcja która jest przechowywaczem punktu w trój wymiarze
 */
class Point {
public:
	int X, //<! Współrzędna X
		Y, //<! Współrzędna Y
		Z; //<! Współrzędna Z

	/**
	 * Konstruktor
	 * @param x Współrzędna X
	 * @param y Współrzędna Y
	 */
	Point(int x, int y);

	/**
	 * Konstruktor
	 * @param x Współrzędna X
	 * @param y Współrzędna Y
	 * @param z Współrzędna Z
	 */
	Point(int x, int y, int z);

	/**
	 * Transformator punktu dwuwymiarowego na trójwymiarowy
	 * @param x Współrzędna X
	 * @param y Współrzędna Y
	 * @param z Współrzędna Z
	 */
	static Point Transform(int x = 0, int y = 0, int z = 0);
};
