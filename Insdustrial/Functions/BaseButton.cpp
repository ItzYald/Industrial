#include "BaseButton.h"

BaseButton::BaseButton()
{
}

BaseButton::BaseButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
	buttonColors _baseColors, int outlineSize)
{
	baseColors = _baseColors;
	aimColors = _baseColors;
	leftDownColors = _baseColors;
	rightDownColors = _baseColors;

	Init(_mousePosition, _position, _size, outlineSize);
}

BaseButton::BaseButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
	buttonColors _baseColors, buttonColors _aimColors, int outlineSize)
	: BaseButton(_mousePosition, _position, _size, _baseColors, outlineSize)

{
	aimColors = _aimColors;
	leftDownColors = _aimColors;
	rightDownColors = _aimColors;
}

BaseButton::BaseButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
	buttonColors _baseColors, buttonColors _aimColors, buttonColors _leftDownColors, int outlineSize)
	: BaseButton(_mousePosition, _position, _size, _baseColors, outlineSize)

{
	aimColors = _aimColors;
	leftDownColors = _leftDownColors;
	rightDownColors = _leftDownColors;
}

BaseButton::BaseButton(sf::Vector2i& _mousePosition, sf::Vector2f _position, sf::Vector2f _size,
	buttonColors _baseColors, buttonColors _aimColors, buttonColors _leftDownColors, buttonColors _rightDownColors,
	int outlineSize)
	: BaseButton(_mousePosition, _position, _size, _baseColors, outlineSize)
{
	aimColors = _aimColors;
	leftDownColors = _leftDownColors;
	rightDownColors = _rightDownColors;
}

void BaseButton::Update()
{
	leftClick = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	rightClick = sf::Mouse::isButtonPressed(sf::Mouse::Right);
	if (Aim())
	{
		if (leftClick)
		{
			rectangle.setFillColor(leftDownColors.color);
			rectangle.setOutlineColor(leftDownColors.outLineColor);
		}
		else if (rightClick)
		{
			rectangle.setFillColor(rightDownColors.color);
			rectangle.setOutlineColor(rightDownColors.outLineColor);
		}
		else
		{
			rectangle.setFillColor(aimColors.color);
			rectangle.setOutlineColor(aimColors.outLineColor);
		}
	}
	else
	{
		rectangle.setFillColor(baseColors.color);
		rectangle.setOutlineColor(baseColors.outLineColor);
	}
}

void BaseButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectangle);
}
