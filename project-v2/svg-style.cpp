#include "header.h"

namespace Svg {

	StyleClass::StyleClass(){}

	StyleClass::StyleClass(std::string name) {
		SetName(name);
	}

	void StyleClass::Set(std::string name, std::string value){
		Properties[name] = value;
	};

	std::string StyleClass::ToString() {
		stringstream output;
		output << Name << "{";

		for (std::map<string, string>::iterator prop = Properties.begin(); 
			prop != Properties.end(); prop++) {
			output << prop->first << ":" << prop->second << ";";
		}

		output << "}";

		return output.str();
	};

	void StyleClass::SetName(std::string val) {
		Name = val;
	}

	std::string StyleClass::GetName() {
		return Name;
	}

	StyleClass StyleClass::FillClass(std::string name, std::string fill) {
		StyleClass styleClass = StyleClass(name);
		styleClass.Set("fill", fill);
		return styleClass;
	}

	StyleClass StyleClass::FillClass(std::string name, Color color) {
		StyleClass styleClass = StyleClass(name);
		styleClass.Set("fill", color.ToString());
		return styleClass;
	}
};