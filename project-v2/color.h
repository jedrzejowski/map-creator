#pragma once
#include "header.h"

using namespace std;

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

class Color {
private:
	int Red = 0, Green = 0, Blue = 0;
	float Alpha = 1;
public:

	Color();
	Color(int r, int g, int b);
	Color(int r, int g, int b, float a);

	string ToString();

	int GetRed();
	int GetGreen();
	int GetBlue();
	float GetAlpha();

	void SetRed(int val);
	void SetGreen(int val);
	void SetBlue(int val);
	void SetAlpha(float val);

	void Darken(float value);
	void Lighten(float value);
};