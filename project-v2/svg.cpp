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

		content = new stringstream();
		Width = w;
		Height = h;
	}

	void SvgImage::save(std::string path) {
		ofstream file;
		file.open(path);
			
		file << "<svg xmlns='http://www.w3.org/2000/svg' width='" << Width << "' height='" << Height << "'>";
	
		file << "<style>";
		for (int i = 0, size = styleClasses.size(); i < size; i++)
			file << styleClasses[i].ToString();
		file << "</style>";

		file << content->str();

		file << "</svg>";

		file.close();
	};

	void SvgImage::AddPolygon(Polygon& polygon) {
		(*content) << "<polygon";

		(*content) << " points='";
		for (int i = 0, size = polygon.Points.size() - 1; i <= size; i++) {
			(*content) << polygon.Points[i].X << "," << polygon.Points[i].Y;

			if (i != size)
				(*content) << " ";
		}
		(*content) << "'";

		//Klasy
		if (polygon.Clases.size() > 0) {
			(*content) << " class='";
			for (int i = 0, size = polygon.Clases.size() - 1; i <= size; i++) {
				(*content) << polygon.Clases[i];

				if (i != size)
					(*content) << " ";
			}
			(*content) << "'";
		}

		(*content) << "/>";
	}

	void SvgImage::AddClass(StyleClass classProps) {
		styleClasses.push_back(classProps);
	}

}
