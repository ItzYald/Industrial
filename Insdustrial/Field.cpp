#include "Field.h"

Field::Field(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2i _size, int _sizeOne, sf::Vector2u _sizeW, sf::Texture &texture)
{
	functions = Functions(rw);
	rw = _rw;
	size = _size;
	sizeOne = _sizeOne;
	sizeW = _sizeW;
	sprite = sf::Sprite(texture);
}

void Field::Draw(sf::Vector2f cameraPosition, int i, int j)
{
	sf::Vector2f position = sf::Vector2f(sizeOne * (i - cameraPosition.x), sizeOne * (j - cameraPosition.y));

	if (position.x < sizeW.x && position.y < sizeW.y && position.x + sizeOne > 0 && position.y + sizeOne > 0)
		functions.DrawSprite(rw.get(), sprite, position, sf::Vector2f(sizeOne, sizeOne));
}

sf::Vector2i Field::WhatActive(sf::Vector2i mousePosition)
{
	return sf::Vector2i(0, 0);
}
