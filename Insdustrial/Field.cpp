#include "Field.h"

Field::Field(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2i _size, int _sizeOne, sf::Vector2u _sizeW, sf::Texture& texture)
	: rw(_rw), size(_size), sizeOne(_sizeOne), sizeW(_sizeW)
{
	functions = Functions(rw);
	sprite = sf::Sprite(texture);

	wires = std::vector<std::vector<int>>();
	electricOvens = std::vector<std::vector<int>>();
	energyStorages = std::vector<std::vector<int>>();
	energyHandGenerators = std::vector<std::vector<int>>();

	for (int i = 0; i < size.x; i++)
	{
		wires.push_back(std::vector<int>());
		electricOvens.push_back(std::vector<int>());
		energyStorages.push_back(std::vector<int>());
		energyHandGenerators.push_back(std::vector<int>());
		for (int j = 0; j < size.y; j++)
		{
			wires[i].push_back(-1);
			electricOvens[i].push_back(-1);
			energyStorages[i].push_back(-1);
			energyHandGenerators[i].push_back(-1);
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
			// ��������� �����
			if (position.x < sizeW.x && position.y < sizeW.y && position.x + sizeOne > 0 && position.y + sizeOne > 0)
				functions.DrawSprite(sprite, position, sf::Vector2f(sizeOne, sizeOne));
		}
	}
}

sf::Vector2i Field::WhatActive(sf::Vector2i mousePosition)
{
	return sf::Vector2i(0, 0);
}
