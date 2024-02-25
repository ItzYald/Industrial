#include "Field.h"

Field::Field(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2i _size, int _sizeOne,
	sf::Vector2u _sizeW, sf::Texture& _texture, std::vector<Sprite*>& _objects)
	: rw(_rw), size(_size), sizeOne(_sizeOne), sizeW(_sizeW)
{
	functions = Functions(rw);
	sprite = sf::Sprite(_texture);

	objects = &_objects;

	energyObjectsNumbers = std::vector<std::vector<sf::Vector2i>>();
	transEnergyObjectsNumbers = std::vector<std::vector<int>>();

	for (int i = 0; i < size.x; i++)
	{
		energyObjectsNumbers.push_back(std::vector <sf::Vector2i>());
		transEnergyObjectsNumbers.push_back(std::vector <int>());
		for (int j = 0; j < size.y; j++)
		{
			energyObjectsNumbers[i].push_back(sf::Vector2i(-1, -1));
			transEnergyObjectsNumbers[i].push_back(-1);
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

bool Field::PutObject(sf::Vector2i mousePositionGrid, std::vector<Sprite*> _objects, Item& chooseItem)
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return false;
	}
	int chooseNumber = chooseItem.number;
	if ((chooseNumber == 2 || chooseNumber == 5 || chooseNumber == 8 ||
		chooseNumber == 11 || chooseNumber == 12 || chooseNumber == 13 ||
		chooseNumber == 15 || chooseNumber == 16 || chooseNumber == 17 ||
		chooseNumber == 20 || chooseNumber == 24 || chooseNumber == 28) &&
		chooseItem.quantity > 0)
	{
		bool isNear = false;

		for (size_t i = 0; i < objects->size(); i++)
		{
			if (!isNear)
				isNear = (mousePositionGrid == (sf::Vector2i)(*objects)[i]->position);
		}

		if (!isNear)
		{
			chooseItem.quantity -= 1;
			return true;
		}
	}
	return false;
}

sf::Vector2i Field::WhatActive(sf::Vector2i mousePosition)
{
	return sf::Vector2i(0, 0);
}
