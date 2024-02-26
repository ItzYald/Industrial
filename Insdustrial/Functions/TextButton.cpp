#include "TextButton.h"

TextButton::TextButton()
{
}

TextButton::TextButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size, 
	sf::String message, int characterSize,
	textButtonColors _baseColors, int outlineSize)
{
	baseColors = _baseColors;
	aimColors = _baseColors;
	leftDownColors = _baseColors;
	rightDownColors = _baseColors;

	font = sf::Font();
	font.loadFromFile("Font/Undertale-Font.ttf");
	text = sf::Text(message, font, characterSize);
	text.setPosition(_position);

	rectangle.setOutlineThickness(3);

	Init(_mousePosition, _position, _size, outlineSize);
}

TextButton::TextButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
	sf::String message, int characterSize,
	textButtonColors _baseColors, textButtonColors _aimColors, int outlineSize)
	: TextButton(_mousePosition, _position, _size, message, characterSize, _baseColors, outlineSize)

{
	aimColors = _aimColors;
	leftDownColors = _aimColors;
	rightDownColors = _aimColors;
}

TextButton::TextButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
	sf::String message, int characterSize,
	textButtonColors _baseColors, textButtonColors _aimColors, textButtonColors _leftDownColors, int outlineSize)
	: TextButton(_mousePosition, _position, _size, message, characterSize, _baseColors, outlineSize)

{
	aimColors = _aimColors;
	leftDownColors = _leftDownColors;
	rightDownColors = _leftDownColors;
}

TextButton::TextButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
	sf::String message, int characterSize,
	textButtonColors _baseColors, textButtonColors _aimColors, textButtonColors _leftDownColors, textButtonColors _rightDownColors,
	int outlineSize)
	:TextButton(_mousePosition, _position, _size, message, characterSize, _baseColors, outlineSize)
{
	aimColors = _aimColors;
	leftDownColors = _leftDownColors;
	rightDownColors = _rightDownColors;
}

void TextButton::Update()
{
	leftClick = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	rightClick = sf::Mouse::isButtonPressed(sf::Mouse::Right);
	if (Aim())
	{
		if (leftClick)
		{
			rectangle.setFillColor(leftDownColors.color);
			rectangle.setOutlineColor(leftDownColors.outLineColor);
			text.setFillColor(leftDownColors.textColor);
		}
		else if (rightClick)
		{
			rectangle.setFillColor(rightDownColors.color);
			rectangle.setOutlineColor(rightDownColors.outLineColor);
			text.setFillColor(rightDownColors.textColor);
		}
		else
		{
			rectangle.setFillColor(aimColors.color);
			rectangle.setOutlineColor(aimColors.outLineColor);
			text.setFillColor(aimColors.textColor);
		}
	}
	else
	{
		rectangle.setFillColor(baseColors.color);
		rectangle.setOutlineColor(baseColors.outLineColor);
		text.setFillColor(baseColors.textColor);
	}
}

void TextButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectangle);
	target.draw(text);
}


