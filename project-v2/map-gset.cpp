#include "header.h"


int Map::GetWidth() { return mapSettings->X; }

int Map::GetLength() { return mapSettings->Y; }

int Map::GetMinHeight() { return mapSettings->Z1; }

int Map::GetMaxHeight() { return mapSettings->Z2; }

int Map::GetHeightDiff() { return GetMaxHeight() + GetMinHeight(); }

