/**
 * @file color.h
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
 * Plik z nagłówkowy klasy Svg::Color
 */

#pragma once
#include "header.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

namespace Svg {

	/**
	 * Klasa ma za zadanie trzymać kolor w formacie RGBA,
	 * może również go zmieniać oraz wygenerować postać przyjazną przegkądarkom
	 */
	class Color {
	private:
		int Red = 0, //<! Czerowny kanał
		 	Green = 0, //<! Zielony kanał
			Blue = 0; //<! Niebieski kanał
		float Alpha = 1; //<! Kanał alpha(przezroczystość)
	public:

		/**
		 * Konstruktor domyślny który nic nie robi
		 */
		Color();

		/**
		 * Konstruktor z trzema głównymi parametrami RGB
		 * @param r Czerwieny
		 * @param g Zielony
		 * @param b Niebieski
		 */
		Color(int r, int g, int b);

		/**
		 * Konstruktor z czterema głównymi parametrami RGBA
		 * @param r Czerwieny
		 * @param g Zielony
		 * @param b Niebieski
		 * @param a Przezroczystość
		 */
		Color(int r, int g, int b, float a);


		/**
		 * Funkcja która konwertuje kolor na postać "rgba(255,255,255,1)"
		 * @return postać kolory w trbie przeglądarkowym
		 */
		std::string ToString();

		/**
		 * Zwraca wartość kanału czerwonego
		 */
		int GetRed();

		/**
		 * Zwraca wartość kanału zielonego
		 */
		int GetGreen();

		/**
		 * Zwraca wartość kanału niebieskiego
		 */
		int GetBlue();

		/**
		 * Zwraca wartość kanału przezroczystości
		 */
		float GetAlpha();

		/**
		 * Funckja ustawiająca wartośc kanału czerwonego
		 * **Uwaga**: funckja sama dba aby wartośc była poprawna, w przypadku podania wartośći większej niż 255 lub mniejszej niż 0 funkcja zapisze wartość skrajną
		 * @param val nowa wartość kanału czerowonego
		 */
		void SetRed(int val);

		/**
		 * Funckja ustawiająca wartośc kanału zielonego
		 * **Uwaga**: funckja sama dba aby wartośc była poprawna, w przypadku podania wartośći większej niż 255 lub mniejszej niż 0 funkcja zapisze wartość skrajną
		 * @param val nowa wartość kanału zielonego
		 */
		void SetGreen(int val);

		/**
		 * Funckja ustawiająca wartośc kanału niebieskiego
		 * **Uwaga**: funckja sama dba aby wartośc była poprawna, w przypadku podania wartośći większej niż 255 lub mniejszej niż 0 funkcja zapisze wartość skrajną
		 * @param val nowa wartość kanału niebieskiego
		 */
		void SetBlue(int val);

		/**
		 * Funckja ustawiająca wartośc kanału przezroczystości
		 * **Uwaga**: funckja sama dba aby wartośc była poprawna, w przypadku podania wartośći większej niż 1 lub mniejszej niż 0 funkcja zapisze wartość skrajną
		 * @param val nowa wartość kanału przezroczystości
		 */
		void SetAlpha(float val);

		/**
		 * Funckja sciemniająca kolor o daną wartość
		 * @param  value liczba z przedziału 0-1
		 * @return       nowy, ściemniony kolor
		 */
		Color Darken(float value);

		/**
		 * Funckja rozjaśniająca kolor o daną wartość
		 * @param  value liczba z przedziału 0-1
		 * @return       nowy, rozjaśniony kolor
		 */
		Color Lighten(float value);
	};
};
