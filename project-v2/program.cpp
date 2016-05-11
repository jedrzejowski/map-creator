#include "header.h"

int main(int argc, char* argv[])
{
	Map::GetInstance().SetArgs(argc, argv);
	
	Map::GetInstance().GenerateSurface();

	Map::GetInstance().DrawMap("output.svg");

	cout << "Done !" << endl;

    return 0;
}
