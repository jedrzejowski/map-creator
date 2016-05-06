#include "header.h"

using namespace std;

float average(int val1, int val2, int val3, int val4) {
	float total, div;

	total =
		(val1 != -1 ? val1 : 0) +
		(val2 != -1 ? val2 : 0) +
		(val3 != -1 ? val3 : 0) +
		(val4 != -1 ? val4 : 0);

	div =
		(val1 != -1 ? 1 : 0) +
		(val2 != -1 ? 1 : 0) +
		(val3 != -1 ? 1 : 0) +
		(val4 != -1 ? 1 : 0);

	return (val1+ val2 + val3 + val4) / 4;
}

void square(int x, int y, int size, float offset) {
	
	int ave = average(
		Map::GetInstance().getTerrain(x - size, y - size).getZ(),
		Map::GetInstance().getTerrain(x + size, y - size).getZ(),
		Map::GetInstance().getTerrain(x + size, y + size).getZ(),
		Map::GetInstance().getTerrain(x - size, y + size).getZ()
	);
	Map::GetInstance().getTerrain(x, y).setZ(ave + offset);
}

void diamond(int x, int y, float size, float offset) {
	int ave = average(
		Map::GetInstance().getTerrain(x, y - size).getZ(),
		Map::GetInstance().getTerrain(x + size, y).getZ(),
		Map::GetInstance().getTerrain(x, y + size).getZ(),
		Map::GetInstance().getTerrain(x - size, y).getZ()
	);
	Map::GetInstance().getTerrain(x, y).setZ(ave + offset);
	//cout << "z=" << ave + offset << endl;
}

float random() {
	return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

void divide(float sizeX, float sizeY) {
	float x, y;
	float half = sizeX / 2;
	float scale = Map::GetInstance().getRoughness() * sizeX;

	cout << scale;

	if (half < 0.7) return;

	for (x = half; x < Map::GetInstance().getWidth(); x += sizeX) {
		for (y = half; y < Map::GetInstance().getLength(); y += sizeX) {
			square(x, y, half, random() * scale * 2 - scale);

			//cout << x << "," << y << endl;
		}
	}

	cout << "------------------" << endl;

	for (x = fmod(x + half, sizeX); x <= Map::GetInstance().getWidth(); x += sizeX) {
		for (y = 0; y <= Map::GetInstance().getLength(); y += half) {
			//cout << x << "," << y << endl;
			diamond(x, y, half, random() * scale * 2 - scale);
		}
	}

	//cout << Map::GetInstance().getRoughness() << endl;

	divide(sizeX / 2, sizeY);
}

void Map::GenerateSurface() {

	//Alocate table

	/*getTerrain(0, 0)->setZ(getMaxHeight());
	getTerrain(getWidth() - 2, 0)->setZ(getHeightDiff() / 2);
	getTerrain(getWidth() - 1, getLength() - 1)->setZ(0);
	getTerrain(0, getLength() - 1)->setZ(getHeightDiff() / 2);

	

	divide(Map::GetInstance().getWidth());*/

	srand(time(NULL));

	for (int i = 0; i < getWidth(); i++) {
		surface.push_back(vector<BaseTerrain>());

		for (int j = 0; j < getLength(); j++) {
			surface.at(i).push_back(BaseTerrain(i, j, 0));

			//cout<<getTerrain(i, j).getZ()<<endl;
		}
	}

	getTerrain(0, 0).setZ(getHeightDiff());
	getTerrain(getWidth() - 1, 0).setZ(getHeightDiff() / 2);
	getTerrain(getWidth() - 1, getLength() - 1).setZ(0);
	getTerrain(0, getLength() - 1).setZ(getHeightDiff() / 2);

	divide(Map::GetInstance().getWidth(),0);
}