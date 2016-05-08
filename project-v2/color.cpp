#include "header.h"

using namespace std;

Color::Color() {

}
Color::Color(int r, int g, int b) {
	SetRed(r);
	SetGreen(g);
	SetBlue(b);
}
Color::Color(int r, int g, int b, float a) {
	SetRed(r);
	SetGreen(g);
	SetBlue(b);
	SetAlpha(a);
}

int Color::GetRed() { return Red; }
int Color::GetGreen() { return Green; }
int Color::GetBlue() { return Blue; }
float Color::GetAlpha() { return Alpha; }

void Color::SetRed(int val) { 
	if (val > 255) {
		Red = 255;
		return;
	}

	if (val < 0) {
		Red = 0;
		return;
	}

	Red = val;
}

void Color::SetGreen(int val) {
	if (val > 255) {
		Green = 255;
		return;
	}

	if (val < 0) {
		Green = 0;
		return;
	}

	Green = val;
}

void Color::SetBlue(int val) {
	if (val > 255) {
		Blue = 255;
		return;
	}

	if (val < 0) {
		Blue = 0;
		return;
	}

	Blue = val;
}

void Color::SetAlpha(float val) {
	if (val > 1) {
		Alpha = 1;
		return;
	}

	if (val < 0) {
		Alpha = 0;
		return;
	}

	Alpha = val;
}

string Color::ToString() {
	std::stringstream out;

	out << "rgba(" << Red << "," << Green << "," << Blue << "," << Alpha << ")";

	return out.str();
}