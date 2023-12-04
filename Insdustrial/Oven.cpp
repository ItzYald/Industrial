#include "Oven.h"

Oven::Oven(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne, std::string imageFileName, sf::Vector2f _position)
{
	rw = _rw;
	fieldSizeOne = _fieldSizeOne;
	texture = new sf::Texture();
	texture->loadFromFile(imageFileName);
	sprite.setTexture(*texture);
	position = _position;

	inventory = OvenInventory();

	functions = Functions(rw);

	isOpenInterface = false;

	inventory = OvenInventory(rw);

	sprite.setScale(fieldSizeOne / sprite.getTexture()->getSize().x, fieldSizeOne / sprite.getTexture()->getSize().y);

	for (int i = 0; i < 30; i++)
	{
		ch.push_back(Checks());
	}
}

void Oven::NearPlayer(sf::Vector2f playerPosition, int playerAngle)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
	{
		if (((int)playerPosition.x == position.x && (int)playerPosition.y == position.y + 1 && playerAngle == 0) ||
			((int)playerPosition.x == position.x && (int)playerPosition.y == position.y - 1 && playerAngle == 2) ||
			((int)playerPosition.x == position.x + 1 && (int)playerPosition.y == position.y && playerAngle == 3) ||
			((int)playerPosition.x == position.x - 1 && (int)playerPosition.y == position.y && playerAngle == 1))
		{
			isOpenInterface = true;
		}
		else
		{
			isOpenInterface = false;
		}
	}
	else
	{
		isOpenInterface = false;
	}
}

void Oven::Update(sf::Vector2f playerPosition, int playerAngle)
{
	NearPlayer(playerPosition, playerAngle);
}

