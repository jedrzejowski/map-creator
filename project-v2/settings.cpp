#include "header.h"

using namespace std;

Settings::Settings() {
	X = 50;
	Y = 50;
	Z1 = -25;
	Z2 = 50;

	persistence = 1;
	frequency = 0.05;
	octaves = 3;
	randomseed = rand();
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
				if (line.at(i) == '=') {
					val = line.substr(i + 1, length);
					break;
				}

				prop += line.at(i);
			}
			
			//Setting vals

			if (!prop.compare("lenght")) {
				X = stoi(val);
				continue;
			}

			if (!prop.compare("width")) {
				Y = stoi(val);
				continue;
			}

			if (!prop.compare("minheight")) {
				Z1 = stoi(val);
				continue;
			}

			if (!prop.compare("maxheight")) {
				Z2 = std::stoi(val);
				continue;
			}

			if (!prop.compare("persistence")) {
				persistence = std::stod(val);
				continue;
			}

			if (!prop.compare("frequency")) {
				frequency = std::stod(val);
				continue;
			}

			if (!prop.compare("octaves")) {
				octaves = std::stoi(val);
				continue;
			}

			if (!prop.compare("randomseed")) {
				randomseed = std::stoi(val);
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

	printf(SETTINGS_PRINTF_INT, "length", X);
	printf(SETTINGS_PRINTF_INT, "width", Y);
	printf(SETTINGS_PRINTF_INT, "min-height", Z1);
	printf(SETTINGS_PRINTF_INT, "max-height", Z2);

	printf(SETTINGS_PRINTF_DOUBLE, "persistence", persistence);
	printf(SETTINGS_PRINTF_DOUBLE, "frequency", frequency);
	printf(SETTINGS_PRINTF_INT, "octaves", octaves);
	printf(SETTINGS_PRINTF_INT, "randomseed", randomseed);
}