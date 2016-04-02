#include "header.h"

Map map;

int main(int argc, char **argv) {
	map = Map();

	map.readMapFromFile("input-map.csv");
	map.generateMap("output-map.svg");

	return 0;
}