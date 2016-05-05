#include "header.h"

using namespace std;

void Settings::readFromFile(string path) {
	
	ifstream file(path.c_str());
	
	if (!file.good()) {
		cerr << "Can't access input file" << endl;
		exit(ErrorInputFile);
	}

	int lineNum = 0;
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

			if (!prop.compare("roughness")) {
				Roughness = std::stod(val);
				continue;
			}

			cerr << "Input file at line " << lineNum << ", prop '" << prop << "' is unknown" << endl;
		}
	}
	catch (exception error) {
		cerr << "Input file is broken at line " << lineNum << endl;
		exit(ErrorInputFile);
	}
}