#pragma once
#include "StaingObject.h"
#include "EnergyStorageInventory.h"

// Используется для объектов передающих энергию
template<class T>
class EnergySprite : public StaingObject<T>
{
	
public:
	int turn;

	EnergySprite(){ }
	EnergySprite(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne,
		sf::Texture& _texture, std::vector<sf::Texture>& _textures, sf::Vector2f _position,
		std::vector<sf::Color> _colorsInventory, int type)
	{
		StaingObject<T>::rw = _rw;
		StaingObject<T>::fieldSizeOne = _fieldSizeOne;
		StaingObject<T>::sprite.setTexture(_texture);
		StaingObject<T>::position = _position;

		StaingObject<T>::functions = Functions(StaingObject<T>::rw);

		StaingObject<T>::isOpenInventory = false;

		StaingObject<T>::inventory = T(StaingObject<T>::rw, _colorsInventory, type, _textures);

		StaingObject<T>::sprite.setScale(
			StaingObject<T>::fieldSizeOne / StaingObject<T>::sprite.getTexture()->getSize().x,
			StaingObject<T>::fieldSizeOne / StaingObject<T>::sprite.getTexture()->getSize().y);

		for (int i = 0; i < 30; i++)
		{
			StaingObject<T>::ch.push_back(Checks());
		}
		turn = 0;
	}

	void Update(sf::Vector2f playerPosition, int playerAngle)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
		{
			StaingObject<T>::isOpenInventory = StaingObject<T>::NearPlayer(playerPosition, playerAngle);
		}
		if (StaingObject<T>::ch[0].Check(sf::Keyboard::Key::R))
		{
			if (StaingObject<T>::NearPlayer(playerPosition, playerAngle))
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
			StaingObject<T>::sprite.setRotation(0);
		}
		// Если повернут вправо
		if (turn == 1)
		{
			StaingObject<T>::sprite.setRotation(90);
		}
		// Если повернут вниз
		if (turn == 2)
		{
			StaingObject<T>::sprite.setRotation(180);
		}
		// Если повернут влево
		if (turn == 3)
		{
			StaingObject<T>::sprite.setRotation(270);
		}

		// Задать позицию
		StaingObject<T>::sprite.setPosition(
			StaingObject<T>::fieldSizeOne * (StaingObject<T>::position.x - cameraPosition.x),
			StaingObject<T>::fieldSizeOne * (StaingObject<T>::position.y - cameraPosition.y));

		// Сдвиг для компенсации вращения
		if (StaingObject<T>::sprite.getRotation() == 90)
		{
			StaingObject<T>::sprite.setPosition(
				StaingObject<T>::sprite.getPosition().x + StaingObject<T>::fieldSizeOne,
				StaingObject<T>::sprite.getPosition().y);
		}
		else if (StaingObject<T>::sprite.getRotation() == 180)
		{
			StaingObject<T>::sprite.setPosition(
				StaingObject<T>::sprite.getPosition().x + StaingObject<T>::fieldSizeOne,
				StaingObject<T>::sprite.getPosition().y + StaingObject<T>::fieldSizeOne);
		}
		else if (StaingObject<T>::sprite.getRotation() == 270)
		{
			StaingObject<T>::sprite.setPosition(
				StaingObject<T>::sprite.getPosition().x,
				StaingObject<T>::sprite.getPosition().y + StaingObject<T>::fieldSizeOne);
		}

		StaingObject<T>::rw->draw(StaingObject<T>::sprite);
		sf::Vector2f realPosition = sf::Vector2f(
			StaingObject<T>::fieldSizeOne * (StaingObject<T>::position.x - cameraPosition.x),
			StaingObject<T>::fieldSizeOne * (StaingObject<T>::position.y - cameraPosition.y));
		StaingObject<T>::functions.PrintText(
			std::to_string(StaingObject<T>::inventory.energy),
			sf::Vector2f(realPosition.x + 40, realPosition.y + 40), 15, sf::Color::Red);
	}

};

