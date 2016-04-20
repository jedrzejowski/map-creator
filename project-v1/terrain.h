/**
 * @file terrain.h
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
 * Plik z nagłówkowy klasy Terrain
 */

#pragma once
using namespace std;

/**
 * Klasa mająca za zadanie przechowywać jeden kolcek terenu
 * Jest zarazem listą jednokierunkową
 * <b> Nie tworzyć obiektów tej klasy bezpośrednio, używać funkcji Create() </b>
 */
class Terrain {
public:

	Terrain *Next; //!< Wskaźnik na następny teren
	string Type; //!< Przechowuje typ terenu
	string Texture; //!< Przechowuje rodzaj textury terenu

	int X, //!< Współrzedna X
		Y, //!< Współrzedna Y
		Height; //!< Wysokość nad poziomem morza

	bool Water; //!< Istnienie wody na terenie

	/**
	 * Funkcja do ustawiania wyskości terenu
	 * @param seaLvl wysokość nad poziomem morza
	 */
	void setHeight(int seaLvl);

	/**
	* Funkcja wrysowywania do obrazu S
	* @param svg wysokość nad poziomem morza
	*/
	void drawInSvg(Svg &svg);

	/**
	* Funkcja która jest realnym konstruktorem klasy
	* @param data stream z informacjami z pliku wejściowego
	* @return wskaźnik do utworzonego obiektu
	*/
	static Terrain* Create(stringstream&data);

	/**
	* Wirtualna funkcja do zwracania realnego koloru terenu
	* @return kolor web-html
	*/
	virtual string getSvgColor();
};

/**
 * Klasa terenu typu piaszczystego
 */
class SandTerrain: public Terrain {
	virtual string getSvgColor() override;
};

/**
 * Klasa terenu typu skalistego
 */
class MountainTerrain : public Terrain {
	virtual string getSvgColor() override;
};

/**
 * Klasa terenu typu liściastego
 */
class ForestTerrain : public Terrain {
	virtual string getSvgColor() override;
};
