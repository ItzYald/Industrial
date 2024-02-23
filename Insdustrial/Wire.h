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
	sf::Sprite spriteOn;
	sf::Sprite spriteOff;
	// Количество энергии
	float energy;
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
	/// <param name="textureOn">Текстура во включенном состонии</param>
	/// <param name="textureOff">Текстура в выключенном состонии</param>
	/// <param name="_position">Позиция</param>
	/// <param name="type">Тип (0 - медный, 1 - железный)</param>
	Wire(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition, int _fieldSizeOne,
		sf::Texture& textureOn, sf::Texture& textureOff, sf::Vector2f _position, int _type);
	/// <summary>Есть ли провод перед игроком</summary>
	/// <param name="playerPosition">Позиция игрока</param>
	/// <param name="playerAngle">Угол поворота игрока</param>
	/// <returns>Есть или нет</returns>
	bool NearPlayer(sf::Vector2f playerPosition, int playerAngle);
	void CheckConnections(sf::Vector2f positionSeconObject);
	void Update(sf::Vector2i mousePositionGrid, sf::Vector2f playerPosition, int playerAngle);

	void Next() override{ }
	/// <summary>Отрисовка</summary>
	/// <param name="cameraPosition">Смещение камеры</param>
	void Draw() override;
};

