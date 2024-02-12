#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/Checks.h"

#include "Sprite.h"

#include "Inventory.h"

template<class T>
class StaingObject : public Sprite
{
public:
	// Открыт ли инт
	bool isOpenInventory;
	// Инвентарь (каждый раз разный)
	T inventory;

	StaingObject(){}
	/// <summaryКонструктор</summary>
	/// <param name="_rw">Окно</param>
	/// <param name="_fieldSizeOne">Размер одной ячейки</param>
	/// <param name="_texture">Ссылка на текстуру</param>
	/// <param name="_position">Позиция</param>

	StaingObject(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne, sf::Texture& _texture,
		sf::Vector2f _position, std::vector<sf::Color> _colorsInventory)
	{
		rw = _rw;
		fieldSizeOne = _fieldSizeOne;
		sprite.setTexture(_texture);
		position = _position;

		functions = Functions(rw);

		isOpenInventory = false;

		inventory = T(rw, _colorsInventory);

		sprite.setScale(fieldSizeOne / sprite.getTexture()->getSize().x, fieldSizeOne / sprite.getTexture()->getSize().y);

		for (int i = 0; i < 30; i++)
		{
			ch.push_back(Checks());
		}
	}

	StaingObject(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne,
		sf::Texture& _texture, std::vector<sf::Texture>& _itemTextures,
		sf::Vector2f _position, std::vector<sf::Color> _colorsInventory)
	{
		rw = _rw;
		fieldSizeOne = _fieldSizeOne;
		sprite.setTexture(_texture);
		position = _position;

		functions = Functions(rw);

		isOpenInventory = false;

		inventory = T(rw, _colorsInventory, _itemTextures);

		sprite.setScale(fieldSizeOne / (float)sprite.getTexture()->getSize().x, fieldSizeOne / (float)sprite.getTexture()->getSize().y);

		for (int i = 0; i < 30; i++)
		{
			ch.push_back(Checks());
		}
	}

	StaingObject(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne,
		sf::Texture& _texture, std::vector<sf::Texture>& _itemTextures,
		sf::Vector2f _position, std::vector<sf::Color> _colorsInventory, 
		std::map<std::string, sf::Texture>& _texturesInInventory)
	{
		rw = _rw;
		fieldSizeOne = _fieldSizeOne;
		sprite.setTexture(_texture);
		position = _position;

		functions = Functions(rw);

		isOpenInventory = false;

		inventory = T(rw, _colorsInventory, _itemTextures, _texturesInInventory);

		sprite.setScale(fieldSizeOne / (float)sprite.getTexture()->getSize().x, fieldSizeOne / (float)sprite.getTexture()->getSize().y);

		for (int i = 0; i < 30; i++)
		{
			ch.push_back(Checks());
		}
	}

	/// <summary>Проверка игрока рядом</summary>
	/// <param name="playerPosition">Позиция игрока</param>
	/// <param name="playerAngle">Куда повернут игрок</param>
	/// <returns>Наличие рядом игрока</returns>
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
	/// <summary>
	/// Каждый кадр
	/// </summary>
	/// <param name="playerPosition">Позиция игрока</param>
	/// <param name="playerAngle">Куда повернут игрок</param>
	void Update(sf::Vector2f playerPosition, int playerAngle)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
		{
			isOpenInventory = NearPlayer(playerPosition, playerAngle);
		}
	}
	/// <summary>Отрисовка</summary>
	/// <param name="cameraPosition">Позиция камеры</param>
	void Draw(sf::Vector2f cameraPosition)
	{
		sprite.setPosition(fieldSizeOne * (position.x - cameraPosition.x), fieldSizeOne * (position.y - cameraPosition.y));
		rw->draw(sprite);
	}

};

