/**
* @file svg.cpp
* @author  Adam Jêdrzejowski <a.jedrzejowski@gmail.com>
* @version 1.0
*
* @section LICENSE
*
* Copyright (C) 2016 Adam Jêdrzejowski <a.jedrzejowski@gmail.com>
* This file is part of map-creator
*
* map-creator can not be copied and/or distributed without the express
* permission of Adam Jêdrzejowski
*
* @section DESCRIPTION
*
* Plik z cia³ami klasy Svg
*/

#include "header.h"

namespace Svg {

	SvgImage::SvgImage(int w, int h) : 
		styleClasses() {

		Width = w;
		Height = h;
	}

	void SvgImage::Save(std::string path) {
		ofstream file;
		file.open(path);
			
		file << "<svg xmlns='http://www.w3.org/2000/svg' width='" << Width << "' height='" << Height << "'>";
	
		//Klasy
		file << "<style>";
		for (int i = 0, size = styleClasses.size(); i < size; i++)
			file << styleClasses[i].ToString();
		file << "</style>";

		//Gradienty
		file << "<defs>";
		for (int i = 0, size = linearGradients.size(); i < size; i++)
			file << linearGradients[i].ToString();
		file << "</defs>";

		file << content;
		file << "</svg>";

		file.close();
	};

	void SvgImage::AddPolygon(Polygon polygon) {
		content += polygon.ToString();
	}

	void SvgImage::AddRaw(std::string raw) {
		content += raw;
	}

	void SvgImage::AddText(Text text) {
		content += text.ToString();
	}

	void SvgImage::AddClass(StyleClass classProps) {
		styleClasses.push_back(classProps);
	}

	void SvgImage::AddGradient(LinearGradient gradient) {
		linearGradients.push_back(gradient);
	}

}
