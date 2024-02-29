#include "Field.h"

Field::Field(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition, sf::Vector2i _size, int _sizeOne,
	sf::Vector2u _sizeW, sf::Texture* _texture, std::vector<Object*>& _objects)
	: rw(_rw), size(_size), sizeOne(_sizeOne), sizeW(_sizeW)
{
	functions = Functions(rw);
	sprite = sf::Sprite(*_texture);
	cameraPosition = &_cameraPosition;

	sprite.setScale(_sizeOne / sprite.getTexture()->getSize().x, _sizeOne / sprite.getTexture()->getSize().y);
	
	sprites = std::vector<std::vector<sf::Sprite>>();
	for (size_t i = 0; i < size.x; i++)
	{
		sprites.push_back(std::vector<sf::Sprite>());
		for (size_t j = 0;  j < size.y;  j++)
		{
			sprites[i].push_back(sprite);
		}
	}

	for (size_t i = 0; i < size.x; i++)
	{
		for (size_t j = 0; j < size.y; j++)
		{
			sprites[i][j].setPosition(
				sf::Vector2f(sizeOne * (i - cameraPosition->x), sizeOne * (j - cameraPosition->y)));
		}
	}

	objects = &_objects;

	newEnergyObjectsNumbers = std::vector<std::vector<int>>();
	transEnergyObjectsNumbers = std::vector<std::vector<int>>();

	for (int i = 0; i < size.x; i++)
	{
		newEnergyObjectsNumbers.push_back(std::vector <int>());
		transEnergyObjectsNumbers.push_back(std::vector <int>());
		for (int j = 0; j < size.y; j++)
		{
			newEnergyObjectsNumbers[i].push_back(-1);
			transEnergyObjectsNumbers[i].push_back(-1);
		}
	}

}

void Field::Draw()
{
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++)
		{
			sprite.setPosition(sf::Vector2f(sizeOne * (i - cameraPosition->x), sizeOne * (j - cameraPosition->y)));
			if (sprite.getPosition().x < sizeW.x && sprite.getPosition().y < sizeW.y &&
				sprite.getPosition().x + sizeOne > 0 && sprite.getPosition().y + sizeOne > 0)
			{
				rw->draw(sprite);
			}
		}
	}
}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++)
		{
			if (sprites[i][j].getPosition().x < sizeW.x && sprites[i][j].getPosition().y < sizeW.y &&
				sprites[i][j].getPosition().x + sizeOne > 0 && sprites[i][j].getPosition().y + sizeOne > 0)
			{
				target.draw(sprites[i][j]);
			}
		}
	}
}

void Field::Next()
{
	for (size_t i = 0; i < size.x; i++)
	{
		for (size_t j = 0; j < size.y; j++)
		{
			sprites[i][j].setPosition(
				sf::Vector2f(sizeOne * (i - cameraPosition->x), sizeOne * (j - cameraPosition->y)));
			
		}
	}
}

bool Field::PutObject(sf::Vector2i mousePositionGrid, std::vector<Object*> _objects, Item& chooseItem)
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return false;
	}
	int chooseNumber = chooseItem.number;
	if ((chooseNumber == 2 || chooseNumber == 5 || chooseNumber == 8 ||
		chooseNumber == 11 || chooseNumber == 12 || chooseNumber == 13 ||
		chooseNumber == 15 || chooseNumber == 16 || chooseNumber == 17 ||
		chooseNumber == 20 || chooseNumber == 24 || chooseNumber == 28 ||
		chooseNumber == 32) &&
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
