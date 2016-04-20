/**
 * @file map.h
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
 * Plik z nagłówkowy klasy Map
 */

#pragma once
#include "header.h"

using namespace std;

/**
 * Klasa głowna całego programu do zarządzania całym procesem, na bazie Singleton
 */
class Map {
private:
	vector<Terrain> mapArray; //<! Wskażnik do pierwszego elementu listy z klockami terenowymi
	Map();
public:
	int Height = 0, //<! Wysokość mapy w jednostkach
	 	Width = 0, //<! Szerokość mapy w jednostkach
		HighestPoint, //<! Najwyższy punkt mapy
		LowestPoint; //<! Najniższy punkt mapy

public:

	/**
	 * Funkcja do tworzenia instancji
	 * @return Obiekt singleton
	 */
	static Map& getInstance();

	/**
	 * Funkcja wczytująca parametry mapy z pliku
	 * @param path Ścieżka do pliku z mapą
	 */
	void readMapFromFile(string path);

	/**
	 * Zwraca teren o zadanych wspołrzędnych
	 * @param  x X
	 * @param  y Y
	 * @return   Wskaźnik do terenu
	 */
	Terrain * getTerrain(int x, int y);

	/**
	 * Dodaje teren do mapy
	 * @param terrain Wskaźnik do terenu
	 */
	void addTerrain(Terrain *terrain);

	/**
	 * Funckja generująca wyjściową mape
	 * @param path scieżka do pliku
	 */
	void generateMap(string path);

	/**
	 * Ustawia najwyższy punkt mapy
	 * @param z Wysokość
	 */
	void setHighestPoint(int z);

	/**
	 * Ustawia najniższy punkt mapy
	 * @param z Wysokość
	 */
	void setLowestPoint(int z);
};
