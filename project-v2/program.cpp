#include "header.h"

int main(int argc, char* argv[])
{
	Map::GetInstance().SetArgs(argc, argv);
	
	Map::GetInstance().GenerateSurface();

    return 0;
}

