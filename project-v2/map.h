/**
 * @file map.h
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
 * Plik z nagłówkowy klasy Map
 */

#pragma once
#include "header.h"
#include "settings.h"

/**
 * Klasa singleton, głona instacja programu odpowiedzialna za jego podstawowe funckje
 */
class Map {
	friend class Settings;
private:

	/**
	 * Prywatny konstruktor, a tak żeby nikom nie wpadło zrobić innego obiektu typu Map
	 */
	Map();

	vector<vector<Terrain::Base*>> surface; //<! Dwuwymiarowy wektor trzymający wskaźniki do bloków terenu

	Settings* mapSettings; //<! Wskaźnik na ustawienia mapy

public:

	/**
	 * Funckja sparwiająca, że ta klasa jest typu singleton
	 * @return referencja do jedynego istniejącego obiektu tej klasy
	 */
	static Map& GetInstance();

	/**
	 * Funkcja pobierająca argumenty programu oraz wczytująca plik wejściowy
	 * @param argc ilość argumentów
	 * @param argv tablica argumentów
	 */
	void SetArgs(int argc, char* argv[]);

	/**
	 * Funckja generująca powierzchnie mapy
	 */
	void GenerateSurface();

	/**
	 * Funckja tworzy obraz svg i zapisuje go do pliku
	 * @param path ścierzka do pliku wyjściowego
	 */
	void DrawMap(string path);

	/**
	 * Funkcja do pobierania ternu z zadanych współżędnych
	 * **Uwaga**: w przypadku podania nieprawidłowych danych zostanie zwrócóny teren z karńca mapy, taki, że będzie najbardziej odpowiadał zadanym współżednych
	 * @param  x X
	 * @param  y Y
	 * @return   wskaźnik do ternu
	 */
	static Terrain::Base* GetTerrain(int x, int y);

	/**
	 * Funkcja wkłada nowy teren na zadaną współżędną
	 * @param x       X
	 * @param y       Y
	 * @param terrain nowy teren
	 */
	static void SetTerrain(int x, int y, Terrain::Base* terrain);
};
