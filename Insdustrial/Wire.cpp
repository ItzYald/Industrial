#include "Wire.h"

Wire::Wire(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition, int _fieldSizeOne,
	sf::Texture& textureOn, sf::Texture& textureOff, sf::Vector2f _position, int _type)
{
	rw = _rw;
	fieldSizeOne = _fieldSizeOne;
	functions = Functions(rw);

	cameraPosition = &_cameraPosition;

	sprite = sf::Sprite();
	sprite.setTexture(textureOn);
	sprite.setScale(fieldSizeOne / (float)sprite.getTexture()->getSize().x,
		fieldSizeOne / (float)sprite.getTexture()->getSize().y);

	spriteOn = sf::Sprite();
	spriteOn.setTexture(textureOn);
	spriteOn.setScale(fieldSizeOne / (float)spriteOn.getTexture()->getSize().x,
		fieldSizeOne / (float)spriteOn.getTexture()->getSize().y);

	spriteOff = sf::Sprite();
	spriteOff.setTexture(textureOff);
	spriteOff.setScale(fieldSizeOne / (float)spriteOff.getTexture()->getSize().x,
		fieldSizeOne / (float)spriteOff.getTexture()->getSize().y);

	position = _position;
	energy = 0;

	turn = 0;

	// Если медный
	if (_type == 0)
	{
		maxEnergy = 10;
		power = 10;
	}
	// Если стальной
	else if (_type == 1)
	{
		power = 100;
		maxEnergy = 100;
	}
	// Если оловяный
	else if (_type == 2)
	{
		power = 1000;
		maxEnergy = 1000;
	}

	for (int i = 0; i < 30; i++)
	{
		ch.push_back(Checks());
	}
}

void Wire::CheckConnections(sf::Vector2f positionSeconObject) 
{
	if (position.x + 1 == positionSeconObject.x && position.y == positionSeconObject.y)
	{
		connections[1] = true;
	}
	if (position.x - 1 == positionSeconObject.x && position.y == positionSeconObject.y)
	{
		connections[3] = true;
	}
	if (position.x == positionSeconObject.x && position.y + 1 == positionSeconObject.y)
	{
		connections[2] = true;
	}
	if (position.x == positionSeconObject.x && position.y - 1 == positionSeconObject.y)
	{
		connections[0] = true;
	}
}

bool Wire::NearPlayer(sf::Vector2f playerPosition, int playerAngle)
{
	return (((int)playerPosition.x == position.x && (int)playerPosition.y == position.y + 1 && playerAngle == 0) ||
		((int)playerPosition.x == position.x && (int)playerPosition.y == position.y - 1 && playerAngle == 2) ||
		((int)playerPosition.x == position.x + 1 && (int)playerPosition.y == position.y && playerAngle == 3) ||
		((int)playerPosition.x == position.x - 1 && (int)playerPosition.y == position.y && playerAngle == 1));
}

void Wire::Update(sf::Vector2i mousePositionGrid, sf::Vector2f playerPosition, int playerAngle)
{
	if (ch[0].Check(sf::Keyboard::Key::R))
	{
		if ((position == (sf::Vector2f)mousePositionGrid))
		{
			if (turn < 3)
				turn += 1;
			else
				turn = 0;
		}
	}
}

void Wire::Draw()
{
	sf::Sprite* thisSprite;

	if (energy == 0)
	{
		thisSprite = &spriteOff;
	}
	else
	{
		thisSprite = &spriteOn;
	}

	if (turn == 0)
	{
		thisSprite->setRotation(0);
	}
	if (turn == 1)
	{
		thisSprite->setRotation(90);
	}
	if (turn == 2)
	{
		thisSprite->setRotation(180);
	}
	if (turn == 3)
	{
		thisSprite->setRotation(270);
	}

	// Задать позицию
	thisSprite->setPosition(fieldSizeOne * (position.x - (*cameraPosition).x), fieldSizeOne * (position.y - (*cameraPosition).y));

	// Сдвиг для компенсации вращения
	if (thisSprite->getRotation() == 90)
	{
		thisSprite->setPosition(thisSprite->getPosition().x + fieldSizeOne, thisSprite->getPosition().y);
	}
	else if (thisSprite->getRotation() == 180)
	{
		thisSprite->setPosition(thisSprite->getPosition().x + fieldSizeOne, thisSprite->getPosition().y + fieldSizeOne);
	}
	else if (thisSprite->getRotation() == 270)
	{
		thisSprite->setPosition(thisSprite->getPosition().x, thisSprite->getPosition().y + fieldSizeOne);
	}

	rw->draw(*thisSprite);
	sf::Vector2f realPosition = sf::Vector2f(fieldSizeOne * (position.x - (*cameraPosition).x), fieldSizeOne * (position.y - (*cameraPosition).y));
}
