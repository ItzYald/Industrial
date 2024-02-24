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
#include "EnergyObjectInventory.h"

template<class T>
class EnergyObject : public Sprite
{
public:
	int turn;
	// Открыт ли инт
	bool isOpenInventory;

	T TypeInventory;
	// Инвентарь (каждый раз разный)
	EnergyObjectInventory* inventory;

	EnergyObject(){}
	/// <summaryКонструктор</summary>
	/// <param name="_rw">Окно</param>
	/// <param name="_fieldSizeOne">Размер одной ячейки</param>
	/// <param name="_texture">Ссылка на текстуру</param>
	/// <param name="_position">Позиция</param>
	EnergyObject(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition, int _fieldSizeOne,
		sf::Texture& _texture, std::vector<sf::Texture>& _itemTextures,
		sf::Vector2f _position, std::vector<sf::Color> _colorsInventory)
	{
		Init(_rw, _cameraPosition, _fieldSizeOne, _texture, _itemTextures, _position, _colorsInventory);
		TypeInventory = T(rw, _colorsInventory, _itemTextures);
		inventory = &TypeInventory;
	}

	EnergyObject(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition, int _fieldSizeOne,
		sf::Texture& _texture, std::vector<sf::Texture>& _itemTextures,
		sf::Vector2f _position, std::vector<sf::Color> _colorsInventory,
		std::map<std::string, sf::Texture>& _texturesInInventory)
	{
		Init(_rw, _cameraPosition, _fieldSizeOne, _texture, _itemTextures, _position, _colorsInventory);
		TypeInventory = T(rw, _colorsInventory, _itemTextures, _texturesInInventory);
		inventory = &TypeInventory;
	}

	EnergyObject(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition, int _fieldSizeOne,
		sf::Texture& _texture, std::vector<sf::Texture>& _itemTextures, sf::Vector2f _position,
		std::vector<sf::Color> _colorsInventory, int _maxFuel, int _power)
	{
		Init(_rw, _cameraPosition, _fieldSizeOne, _texture, _itemTextures, _position, _colorsInventory);
		TypeInventory = T(rw, _colorsInventory, _maxFuel, _power, _itemTextures);
		inventory = &TypeInventory;
	}

	EnergyObject(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition, int _fieldSizeOne,
		sf::Texture& _texture, std::vector<sf::Texture>& _itemTextures, sf::Vector2f _position,
		std::vector<sf::Color> _colorsInventory, int _maxFuel, int _power,
		std::map<std::string, sf::Texture>& _texturesInInventory)
	{
		Init(_rw, _cameraPosition, _fieldSizeOne, _texture, _itemTextures, _position, _colorsInventory);
		TypeInventory = T(rw, _colorsInventory, _maxFuel, _power, _itemTextures, _texturesInInventory);
		inventory = &TypeInventory;
	}

	EnergyObject(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition, int _fieldSizeOne,
		sf::Texture& _texture, std::vector<sf::Texture>& _itemTextures, sf::Vector2f _position,
		std::vector<sf::Color> _colorsInventory, int _maxFuel)
	{
		Init(_rw, _cameraPosition, _fieldSizeOne, _texture, _itemTextures, _position, _colorsInventory);
		TypeInventory = T(rw, _colorsInventory, _maxFuel, _itemTextures);
		inventory = &TypeInventory;
	}

	void Init(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition, int _fieldSizeOne,
		sf::Texture& _texture, std::vector<sf::Texture>& _itemTextures,
		sf::Vector2f _position, std::vector<sf::Color> _colorsInventory)
	{
		rw = _rw;
		fieldSizeOne = _fieldSizeOne;
		sprite.setTexture(_texture);
		position = _position;

		cameraPosition = &_cameraPosition;

		functions = Functions(rw);

		isOpenInventory = false;

		turn = 0;
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
	// Обновление инвентаря
	void Next() override
	{
		inventory->Next();
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
		sprite.setPosition(
			fieldSizeOne * (position.x - (*cameraPosition).x),
			fieldSizeOne * (position.y - (*cameraPosition).y));

		// Сдвиг для компенсации вращения
		if (sprite.getRotation() == 90)
		{
			sprite.setPosition(
				sprite.getPosition().x + fieldSizeOne,
				sprite.getPosition().y);
		}
		else if (sprite.getRotation() == 180)
		{
			sprite.setPosition(
				sprite.getPosition().x + fieldSizeOne,
				sprite.getPosition().y + fieldSizeOne);
		}
		else if (sprite.getRotation() == 270)
		{
			sprite.setPosition(
				sprite.getPosition().x,
				sprite.getPosition().y + fieldSizeOne);
		}

		//rw->draw(sprite);
		//sf::Vector2f realPosition = sf::Vector2f(
		//	fieldSizeOne * (position.x - (*cameraPosition).x),
		//	fieldSizeOne * (position.y - (*cameraPosition).y));
	}
	/// <summary>
	/// Каждый кадр
	/// </summary>
	/// <param name="playerPosition">Позиция игрока</param>
	/// <param name="playerAngle">Куда повернут игрок</param>
	void Update(sf::Vector2i mousePositionGrid, sf::Vector2f playerPosition, int playerAngle)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			isOpenInventory = (position == (sf::Vector2f)mousePositionGrid);
		}
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
	/// <summary>Отрисовка</summary>
	/// <param name="cameraPosition">Позиция камеры</param>
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(sprite);
	}


};

