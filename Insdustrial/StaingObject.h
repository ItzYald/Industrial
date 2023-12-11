#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions.h"

#include "Object.h"
#include "Checks.h"

#include "OvenInventory.h"

template<class T>
class StaingObject : Object
{
public:

	//Functions functions;
	bool isOpenInterface;

	T inventory;

	StaingObject();
	StaingObject(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne, std::string imageFileName, sf::Vector2f _position)
	{
		rw = _rw;
		fieldSizeOne = _fieldSizeOne;
		texture = new sf::Texture();
		texture->loadFromFile(imageFileName);
		sprite.setTexture(*texture);
		position = _position;

		functions = Functions(rw);

		isOpenInterface = false;

		inventory = T(rw);

		sprite.setScale(fieldSizeOne / sprite.getTexture()->getSize().x, fieldSizeOne / sprite.getTexture()->getSize().y);

		for (int i = 0; i < 30; i++)
		{
			ch.push_back(Checks());
		}
	}

	bool NearPlayer(sf::Vector2f playerPosition, int playerAngle)
	{
		if (((int)playerPosition.x == position.x && (int)playerPosition.y == position.y + 1 && playerAngle == 0) ||
			((int)playerPosition.x == position.x && (int)playerPosition.y == position.y - 1 && playerAngle == 2) ||
			((int)playerPosition.x == position.x + 1 && (int)playerPosition.y == position.y && playerAngle == 3) ||
			((int)playerPosition.x == position.x - 1 && (int)playerPosition.y == position.y && playerAngle == 1))
		{
			return true;
		}
		return false;
	}
	void Update(sf::Vector2f playerPosition, int playerAngle)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
		{
			isOpenInterface = NearPlayer(playerPosition, playerAngle);
		}
	}

	void Draw(sf::Vector2f cameraPosition)
	{
		sprite.setPosition(fieldSizeOne * (position.x - cameraPosition.x), fieldSizeOne * (position.y - cameraPosition.y));
		(*rw).draw(sprite);
	}

};

