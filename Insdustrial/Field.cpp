#include "Field.h"

Field::Field(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2i _size, int _sizeOne, sf::Vector2u _sizeW, sf::Texture& texture)
	: rw(_rw), size(_size), sizeOne(_sizeOne), sizeW(_sizeW)
{
	functions = Functions(rw);
	sprite = sf::Sprite(texture);

	energyObjects = std::vector<std::vector<sf::Vector2i>>();

	for (int i = 0; i < size.x; i++)
	{
		energyObjects.push_back(std::vector <sf::Vector2i>());
		for (int j = 0; j < size.y; j++)
		{
			energyObjects[i].push_back(sf::Vector2i(-1, -1));
		}
	}

}

void Field::Draw(sf::Vector2f cameraPosition)
{
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++)
		{
			sf::Vector2f position = sf::Vector2f(sizeOne * (i - cameraPosition.x), sizeOne * (j - cameraPosition.y));
			// Отрисовка травы
			if (position.x < sizeW.x && position.y < sizeW.y && position.x + sizeOne > 0 && position.y + sizeOne > 0)
				functions.DrawSprite(sprite, position, sf::Vector2f(sizeOne, sizeOne));
		}
	}
}

sf::Vector2i Field::WhatActive(sf::Vector2i mousePosition)
{
	return sf::Vector2i(0, 0);
}
