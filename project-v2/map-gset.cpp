#include "header.h"


int Map::GetWidth() { return mapSettings->Width; }

int Map::GetLength() { return mapSettings->Length; }

int Map::GetAmplitude() { return mapSettings->Amplitude; }

int Map::GetLowestPoint() { return LowestPoint; }

void Map::SetLowestPoint(int z) {
	LowestPoint = z < LowestPoint ? z : LowestPoint;
}