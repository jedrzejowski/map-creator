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


int main(int argc, char **argv) {
	Map::getInstance().readMapFromFile("input-map.csv");
	Map::getInstance().generateMap("output-map.svg");

	return 0;
}
