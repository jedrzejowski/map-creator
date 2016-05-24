#include "header.h"

namespace Svg {
	Text::Text() {
	}

	Text::Text(std::string content) {
		SetContent(content);
	}

	Text::Text(std::string content, Color color, int x, int y) {
		SetContent(content);
		SetColor(color);
		SetXY(x, y);
	}

	void Text::SetContent(std::string content) {
		this->content = content;
	}

	std::string Text::GetContent() {
		return content;
	}

	void Text::SetWeigth(TextWeigth weigth) {
		this->weigth = weigth;
	}

	TextWeigth Text::GetWeigth() {
		return weigth;
	}

	void Text::SetColor(Color color) {
		this->color = color;
	}
	Color Text::GetColor() {
		return color;
	}

	void Text::SetXY(int x, int y) {
		this->x = x;
		this->y = y;
	}

	std::string Text::ToString() {
		string output = "<text";
		output += " x='" + to_string(x) + "'";
		output += " y='" + to_string(y) + "'";
		output += " fill='" + color.ToString() + "'";
		output += " style='font-weight:normal;'";
		output += ">" + content + "</text>";
		return output;
	}
}