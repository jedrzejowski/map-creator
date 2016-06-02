/**
 * @file program.cpp
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
 * Plik z ciałem programu(funcja main)
 */

#include "header.h"

int main(int argc, char* argv[])
{
	srand(time(NULL));

	Map::GetInstance().SetArgs(argc, argv);

	Map::GetInstance().GenerateSurface();

	Map::GetInstance().DrawMap("output.svg");

	cout << "Done !" << endl;

    return 0;
}
