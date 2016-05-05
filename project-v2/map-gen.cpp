#include "header.h"

using namespace std;

double average(int val1, int val2, int val3, int val4) {	
	return (val1 + val2 + val3 + val4) / 4;
}

void square(int x, int y, int size, double offset) {
	
	int ave = average(
		Map::GetInstance().getTerrain(x - size, y - size)->getZ(),
		Map::GetInstance().getTerrain(x + size, y - size)->getZ(),
		Map::GetInstance().getTerrain(x + size, y + size)->getZ(),
		Map::GetInstance().getTerrain(x - size, y + size)->getZ()
	);
	Map::GetInstance().getTerrain(x, y)->setZ(ave + offset);
}

void diamond(int x, int y, int size, double offset) {
	int ave = average(
		Map::GetInstance().getTerrain(x, y - size)->getZ(),
		Map::GetInstance().getTerrain(x + size, y)->getZ(),
		Map::GetInstance().getTerrain(x, y + size)->getZ(),
		Map::GetInstance().getTerrain(x - size, y)->getZ()
	);
	Map::GetInstance().getTerrain(x, y)->setZ(ave + offset);
}

void divide(double size) {
	int x, y;
	double half = size / 2;
	double scale = Map::GetInstance().getWidth() * size;

	if (half < 1) return;

	for (x = half; x < Map::GetInstance().getWidth(); x += size) {
		for (y = half; y < Map::GetInstance().getLength(); y += size) {
			square(x, y, half, rand() * scale * 2 - scale);
		}
	}

	for (x = (int)(y + half) % (int)(size); x <= Map::GetInstance().getWidth(); x += size) {
		for (y = 0; y <= Map::GetInstance().getLength(); y += half) {
			diamond(x, y, half, rand() * scale * 2 - scale);
		}
	}

	cout << scale << endl;
	
	divide(size / 2);
}

void Map::GenerateSurface() {

	//Alocate table
	surface = new BaseTerrain*[getWidth()];
	for (int i = 0; i < getWidth(); ++i)
		surface[i] = new BaseTerrain[5];

	getTerrain(0, 0)->setZ(getMaxHeight());
	getTerrain(getWidth() - 2, 0)->setZ(getHeightDiff() / 2);
	getTerrain(getWidth() - 1, getLength() - 1)->setZ(0);
	getTerrain(0, getLength() - 1)->setZ(getHeightDiff() / 2);

	srand(time(NULL));

	divide(Map::GetInstance().getWidth());


}