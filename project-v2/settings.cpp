#include "header.h"

using namespace std;

Settings::Settings() {
	Width = DEFAULT_MAP_WIDTH;
	Length = DEFAULT_MAP_LENGTH;
	Amplitude = DEFAULT_MAP_AMPLITUDE;

	Persistence = DEFAULT_MAP_PERSISTENCE;
	Frequency = DEFAULT_MAP_FREQUENCY;
	Octaves = DEFAULT_MAP_OCTAVES;

	Randomseed = rand();
}


void Settings::ReadFromFile(string path) {

	ifstream file(path.c_str());
	int lineNum = 0;

	if (!file.good()) {
		if (!path.compare(DEFAULT_INPUT_FILE)) {
			cerr << "Can't access input file" << endl;
			exit(ErrorInputFile);
		}
		goto printSettings;
	}

	try {
		string line, prop, val;
		int length;
		while (getline(file, line)) {

			prop = string();
			val = string();
			length = line.length();
			lineNum++;

			for (int i = 0; i < length; i++) {
				if (line.at(i) == '#') break;

				if (line.at(i) == '=') {
					val = line.substr(i + 1, length);
					break;
				}

				prop += line.at(i);
			}

			//Setting vals

			if (!prop.compare("lenght")) {
				Width = stoi(val);
				continue;
			}

			if (!prop.compare("width")) {
				Length = stoi(val);
				continue;
			}

			if (!prop.compare("amplitude")) {
				Amplitude = stod(val);
				continue;
			}

			if (!prop.compare("persistence")) {
				Persistence = std::stod(val);
				continue;
			}

			if (!prop.compare("frequency")) {
				Frequency = std::stod(val);
				continue;
			}

			if (!prop.compare("octaves")) {
				Octaves = std::stoi(val);
				continue;
			}

			if (!prop.compare("randomseed")) {
				Randomseed = std::stoi(val);
				continue;
			}

			if (!prop.compare("lowgraphic")) {
				if(!val.compare("1") || !val.compare("true"))
					LowGraphic = true;
				continue;
			}

			cerr << "Input file at line " << lineNum << ", prop '" << prop << "' is unknown" << endl;
		}
	}
	catch (exception error) {

		cerr << "Input file is broken at line " << lineNum << endl;
		exit(ErrorInputFile);
	}

printSettings:
	cout << "Map settings:" << endl;

	#define SETTINGS_PRINTF_INT    ANSI_COLOR_CYAN "  %-15s" ANSI_COLOR_RESET " = %d\n"
	#define SETTINGS_PRINTF_DOUBLE ANSI_COLOR_CYAN "  %-15s" ANSI_COLOR_RESET " = %f\n"

	printf(SETTINGS_PRINTF_INT, "width", Width);
	printf(SETTINGS_PRINTF_INT, "length", Length);
	printf(SETTINGS_PRINTF_DOUBLE, "amplitude", Amplitude);
	printf(SETTINGS_PRINTF_DOUBLE, "persistence", Persistence);
	printf(SETTINGS_PRINTF_DOUBLE, "frequency", Frequency);
	printf(SETTINGS_PRINTF_INT, "octaves", Octaves);
	printf(SETTINGS_PRINTF_INT, "randomseed", Randomseed);

}

int Settings::GetWidth() {
	return Map::GetInstance().mapSettings->Width;
}

int Settings::GetLength() {
	return  Map::GetInstance().mapSettings->Length;
}

double Settings::GetPersistence() {
	return Map::GetInstance().mapSettings->Persistence;
}

double Settings::GetFrequency() {
	return Map::GetInstance().mapSettings->Frequency;
}

double Settings::GetAmplitude() {
	return Map::GetInstance().mapSettings->Amplitude;
}

int Settings::GetOctaves() {
	return Map::GetInstance().mapSettings->Octaves;
}

int Settings::GetRandomseed() {
	return Map::GetInstance().mapSettings->Randomseed;
}

int Settings::GetLowestPoint() {
	return  LowestPoint;
}

void Settings::SetLowestPoint(int z) {
	LowestPoint = z < LowestPoint ? z : LowestPoint;
}

bool Settings::IsLowGraphic() {
	return Map::GetInstance().mapSettings->LowGraphic;
}

bool Settings::SmoothTerrainCross() {
	return !IsLowGraphic();
}
