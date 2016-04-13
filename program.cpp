/**
 * @file program.cpp
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
 * Plik z głowną pętlą programu
 */

#include "header.h"

Map map;

int main(int argc, char **argv) {
	map = Map();

	map.readMapFromFile("input-map.csv");
	map.generateMap("output-map.svg");

	return 0;
}
