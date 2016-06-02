/**
 * @file settings.h
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
 * Plik z nagłówkowy klasy Settings
 */

#pragma once
#include "header.h"

#define DEFAULT_INPUT_FILE "input.ini"

#define DEFAULT_MAP_WIDTH 50
#define DEFAULT_MAP_LENGTH 50
#define DEFAULT_MAP_AMPLITUDE 50
#define DEFAULT_MAP_PERSISTENCE 1
#define DEFAULT_MAP_FREQUENCY 0.05
#define DEFAULT_MAP_OCTAVES 3

using namespace std;

/**
 * Klasa ładująca, trzymająca i udostępniająca ustawienia mapy
 */
class Settings {
	friend class Map;
	int Width, //<! Szerokośc mapy
		Length; //<! Długość mapy
	int LowestPoint; //<! Najniźszy punkt mapy

	double Persistence, Frequency, Amplitude;
	int Octaves, Randomseed;

	bool LowGraphic = false; //<! Ustawienie niskiej grafiki
public:

	/**
	 * Konstruktor, ustawia wartości domyslne ustawień mapy oraz generuje random seed mapy
	 */
	Settings();

	/**
	 * Wczytuje ustawienia mapy z pliku
	 * @param path ścieżka do pliku
	 */
	void ReadFromFile(string path);

	static int GetLength();
	static int GetWidth();

	static double GetPersistence();
	static double GetFrequency();
	static double GetAmplitude();
	static int GetOctaves();
	static int GetRandomseed();

	static void SetLowestPoint(int z);
	static int GetLowestPoint();

	static bool IsLowGraphic();
	static bool SmoothTerrainCross();

};
