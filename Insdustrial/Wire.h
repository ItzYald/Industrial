#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Sprite.h"

class Wire : public Sprite
{
public:
	// Кол-во соединений между проводами и механизмами
	bool connections[4] = { 0, 0, 0, 0 };

	// Список спрайтов
	sf::Sprite sprite;
	// Количество энергии
	int energy;
	// Максимально хранимая энергия
	int maxEnergy;
	// Сила, с которой может передавать энергию провод
	int power;

	// Номер оотрисовываемого спрайта (в зависимости от связей)
	int numberSprite;
	// Поворот (куда направлен выход)
	int turn;

	Wire(){ }
	/// <summary>Конструктор</summary>
	/// <param name="_rw">Окно</param>
	/// <param name="_fieldSizeOne">Размер одной ячейки</param>
	/// <param name="texture">Текстура</param>
	/// <param name="_position">Позиция</param>
	/// <param name="type">Тип (0 - медный, 1 - железный)</param>
	Wire(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne,
		sf::Texture& texture, sf::Vector2f _position, int _type);
	/// <summary>Есть ли провод перед игроком</summary>
	/// <param name="playerPosition">Позиция игрока</param>
	/// <param name="playerAngle">Угол поворота игрока</param>
	/// <returns>Есть или нет</returns>
	bool NearPlayer(sf::Vector2f playerPosition, int playerAngle);
	void CheckConnections(sf::Vector2f positionSeconObject);
	void Update(sf::Vector2f playerPosition, int playerAngle);
	/// <summary>Отрисовка</summary>
	/// <param name="cameraPosition">Смещение камеры</param>
	void Draw(sf::Vector2f cameraPosition);
};

