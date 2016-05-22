#include "header.h"

namespace Svg {

	//
	//GradientStop
	//

	GradientStop::GradientStop() {

	}

	GradientStop::GradientStop(float offset, Color color) {
		SetOffset(offset);
		SetColor(color);
	}

	void GradientStop::SetColor(Color color) {
		this->color = color;
	}

	Color GradientStop::GetColor() {
		return color;
	}

	void GradientStop::SetOffset(float offset) {
		this->offset = offset;
	}

	float GradientStop::GetOffset() {
		return offset;
	}

	std::string GradientStop::ToString() {
		stringstream stream;
		stream << "<stop offset='" << offset * 100 << "%' style='stop-color:" << color.ToString() << "'/>";
		return stream.str();
	}

	//
	//LinearGradient
	//

	LinearGradient::LinearGradient() {
	}

	LinearGradient::LinearGradient(std::string name) {
		SetName(name);
	}

	void LinearGradient::AddStop(GradientStop stop) {
		Stops.push_back(stop);
	}

	void LinearGradient::SetName(std::string val) {
		Name = val;
	}

	std::string LinearGradient::GetName(){
		return Name;
	}

	void LinearGradient::SetPath(float x1, float y1, float x2, float y2) {
		X1 = x1;
		Y1 = y1; 
		X2 = x2;
		Y2 = y2;
	}

	std::string LinearGradient::ToString() {
		stringstream stream;
		stream << "<linearGradient id='" << Name << "' x1='" << X1 * 100 << "%' y1='" << Y1 * 100 << "%' x2='" << X2 * 100 << "%' y2='" << Y2 * 100 << "%'>";

		for (int i = 0, size = Stops.size(); i < size; i++)
			stream << Stops[i].ToString();

		stream << "</linearGradient>";
		return stream.str();
	}
};