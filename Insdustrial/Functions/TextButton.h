#pragma once
#include "Button.h"

struct textButtonColors
{
	sf::Color color = sf::Color(255, 255, 255);
	sf::Color outLineColor = sf::Color::Transparent;
	sf::Color textColor = sf::Color::Transparent;
	textButtonColors(){ }
	textButtonColors(sf::Color _color, sf::Color _outLineColor, sf::Color _textColor)
	{
		color = _color;
		outLineColor = _outLineColor;
		textColor = _textColor;
	}
};

class TextButton : public Button
{
private:
	textButtonColors baseColors;
	textButtonColors aimColors;
	textButtonColors leftDownColors;
	textButtonColors rightDownColors;
	sf::Text text;
	sf::Font font;

public:
	TextButton();

	TextButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
		sf::String message, int characterSize,
		textButtonColors _baseColors,
		int outlineSize = 0);

	TextButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
		sf::String message, int characterSize,
		textButtonColors _baseColors, textButtonColors _aimColors,
		int outlineSize = 0);

	TextButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
		sf::String message, int characterSize,
		textButtonColors _baseColors, textButtonColors _aimColors, textButtonColors _leftDownColors,
		int outlineSize = 0);

	TextButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
		sf::String message, int characterSize,
		textButtonColors _baseColors, textButtonColors _aimColors, textButtonColors _leftDownColors, textButtonColors _rightDownColors,
		int outlineSize = 0);

	void Update() override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

