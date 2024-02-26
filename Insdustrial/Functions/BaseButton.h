#pragma once
#include "Button.h"

struct buttonColors
{
	sf::Color color = sf::Color(255, 255, 255);
	sf::Color outLineColor = sf::Color::Transparent;
	buttonColors(){ }
	buttonColors(sf::Color _color, sf::Color _outLineColor)
	{
		color = _color;
		outLineColor = _outLineColor;
	}
};

class BaseButton : public Button
{
private:
	buttonColors baseColors;
	buttonColors aimColors;
	buttonColors leftDownColors;
	buttonColors rightDownColors;

public:
	BaseButton();

	BaseButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
		buttonColors _baseColors,
		int outlineSize = 0);

	BaseButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
		buttonColors _baseColors, buttonColors _aimColors,
		int outlineSize = 0);

	BaseButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
		buttonColors _baseColors, buttonColors _aimColors, buttonColors _leftDownColors,
		int outlineSize = 0);

	BaseButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
		buttonColors _baseColors, buttonColors _aimColors, buttonColors _leftDownColors, buttonColors _rightDownColors,
		int outlineSize = 0);

	void Update() override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

