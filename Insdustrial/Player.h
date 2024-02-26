#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/OldButton.h"

#include "Sprite.h"
#include "StaticSprites.h"
#include "Inventory.h"
#include "StaingObject.h"

class Player : public Sprite
{
private:
	Functions functions;
	// Скорость ходьбы/бега
	float run;

	sf::Sprite sprite1;
	sf::Sprite sprite2;

public:
	// Инвентарь
	Inventory inventory;

	// Угол игрока
	int angle;
	bool isOpenInventory;
	int newWhatTypeInventoryOpen;
	int newWhatNumberInventoryOpen;

	Player(){ }
	/// <summary>Конструктор</summary>
	/// <param name="_rw">Окно</param>
	/// <param name="_fieldSizeOne">Размер одной ячейки</param>
	/// <param name="_texture">Текстура</param>
	/// <param name="_position">Позиция</param>
	/// <param name="_colorsInventory">Базовые цвета инвентаря</param>
	/// <param name="_textures">Текстуры предметов</param>
	Player(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f& _cameraPosition, int _fieldSizeOne,
		sf::Texture& _texture, sf::Vector2f _position,
		std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture>& _itemTextures);

	// Ходьба игрока
	void Move();
	//Каждый кадр
	void Update();

	void Next() override{ }
	// Отрисовка
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

