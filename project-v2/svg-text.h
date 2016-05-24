#pragma once
#include "svg.h"
namespace Svg {
	enum TextWeigth { Normal, Bold };

	class Text {
	private:
		std::string content;
		TextWeigth weigth;
		Color color;
		int x, y;
	public:
		Text();
		Text(std::string content);
		Text(std::string content, Color color, int x, int y);

		void SetContent(std::string content);
		std::string GetContent();
		
		void SetWeigth(TextWeigth weigth);
		TextWeigth GetWeigth();

		void SetColor(Color color);
		Color GetColor();

		void SetXY(int x, int y);

		std::string ToString();
	};
}

