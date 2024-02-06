#pragma once
#include "StaingObject.h"
#include "EnergyStorageInventory.h"

class EnergyStorageSprite : public StaingObject<EnergyStorageInventory>
{
	
public:
	int turn;

	EnergyStorageSprite(){ }
	EnergyStorageSprite(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne, sf::Texture& _texture, sf::Vector2f _position, std::vector<sf::Color> _colorsInventory, int type)
	{
		rw = _rw;
		fieldSizeOne = _fieldSizeOne;
		sprite.setTexture(_texture);
		position = _position;

		functions = Functions(rw);

		isOpenInventory = false;

		inventory = EnergyStorageInventory(rw, _colorsInventory, type);

		sprite.setScale(fieldSizeOne / sprite.getTexture()->getSize().x, fieldSizeOne / sprite.getTexture()->getSize().y);

		for (int i = 0; i < 30; i++)
		{
			ch.push_back(Checks());
		}
		turn = 0;
	}

	void Update(sf::Vector2f playerPosition, int playerAngle)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
		{
			isOpenInventory = NearPlayer(playerPosition, playerAngle);
		}
		if (ch[0].Check(sf::Keyboard::Key::R))
		{
			if (NearPlayer(playerPosition, playerAngle))
			{
				if (turn < 3)
					turn += 1;
				else
					turn = 0;
			}
		}
	}

	void Draw(sf::Vector2f cameraPosition)
	{
		// Если повернут вверх
		if (turn == 0)
		{
			sprite.setRotation(0);
		}
		// Если повернут вправо
		if (turn == 1)
		{
			sprite.setRotation(90);
		}
		// Если повернут вниз
		if (turn == 2)
		{
			sprite.setRotation(180);
		}
		// Если повернут влево
		if (turn == 3)
		{
			sprite.setRotation(270);
		}

		// Задать позицию
		sprite.setPosition(fieldSizeOne * (position.x - cameraPosition.x), fieldSizeOne * (position.y - cameraPosition.y));

		// Сдвиг для компенсации вращения
		if (sprite.getRotation() == 90)
		{
			sprite.setPosition(sprite.getPosition().x + fieldSizeOne, sprite.getPosition().y);
		}
		else if (sprite.getRotation() == 180)
		{
			sprite.setPosition(sprite.getPosition().x + fieldSizeOne, sprite.getPosition().y + fieldSizeOne);
		}
		else if (sprite.getRotation() == 270)
		{
			sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + fieldSizeOne);
		}

		rw->draw(sprite);
		sf::Vector2f realPosition = sf::Vector2f(fieldSizeOne * (position.x - cameraPosition.x), fieldSizeOne * (position.y - cameraPosition.y));
		functions.PrintText(std::to_string(inventory.energy), sf::Vector2f(realPosition.x + 40, realPosition.y + 40), 15, sf::Color::Red);
	}

};

