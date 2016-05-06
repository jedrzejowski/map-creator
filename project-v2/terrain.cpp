#include "header.h"

using namespace std;

int BaseTerrain::getX() {
	return X;
}

int BaseTerrain::getY() {
	return Y;
}

int BaseTerrain::getZ() {
	return Z;
}

void BaseTerrain::setX(int val) {
	X = val;
}

void BaseTerrain::setY(int val) {
	Y = val;
}

void BaseTerrain::setZ(int val) {
	Z = val;
}

BaseTerrain::BaseTerrain() { }

BaseTerrain::BaseTerrain(int x, int y) {
	setX(x);
	setY(y);

	setZ(rand() % Map::GetInstance().getHeightDiff());
}

BaseTerrain::BaseTerrain(int x, int y, int z) {
	setX(x);
	setY(y);
	setZ(z);
}