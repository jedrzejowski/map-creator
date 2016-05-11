#pragma once
#include "header.h"

namespace Svg {

	class StyleClass {
	private:
		std::string Name;
		std::map<std::string, std::string> Properties;
	public:
		StyleClass();
		StyleClass(std::string name);

		void Set(std::string name, std::string value);
		std::string ToString();

		void SetName(std::string val);
		std::string GetName();
	};
};