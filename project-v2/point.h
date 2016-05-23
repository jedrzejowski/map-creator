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
	float X, //<! Współrzędna X
		Y, //<! Współrzędna Y
		Z; //<! Współrzędna Z

	/**
	 * Konstruktor
	 * @param x Współrzędna X
	 * @param y Współrzędna Y
	 */
	Point(float x, float y);

	/**
	 * Konstruktor
	 * @param x Współrzędna X
	 * @param y Współrzędna Y
	 * @param z Współrzędna Z
	 */
	Point(float x, float y, float z);

	/**
	 * Transformator punktu dwuwymiarowego na trójwymiarowy
	 * @param x Współrzędna X
	 * @param y Współrzędna Y
	 * @param z Współrzędna Z
	 */
	static Point Transform(float x = 0, float y = 0, float z = 0);
};
