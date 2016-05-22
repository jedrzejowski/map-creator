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

	std::string LinearGradient::ToString() {
	}

	void LinearGradient::SetName(std::string val) {
		Name = val;
	}

	std::string LinearGradient::GetName(){
		return Name;
	}
};