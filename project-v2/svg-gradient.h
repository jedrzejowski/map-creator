#pragma once
#include "header.h"

namespace Svg {

	class GradientStop {
		private:
		float offset;
		Color color;

		public:
		GradientStop();
		GradientStop(float offset, Color color);

		void SetColor(Color color);
		Color GetColor();
		void SetOffset(float offset);
		float GetOffset();

		std::string ToString();
	};

	class LinearGradient {
		private:
		std::string Name;
		std::vector<GradientStop> Stops;
		float X1, Y1, X2, Y2;

		public:
		LinearGradient();
		LinearGradient(std::string name);

		void AddStop(GradientStop stop);
		void SetPath(float x1, float y1, float x2, float y2);

		std::string ToString();

		void SetName(std::string val);
		std::string GetName();
	};
};