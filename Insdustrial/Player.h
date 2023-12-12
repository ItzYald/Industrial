#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions.h"
#include "Button.h"

#include "Sprite.h"
#include "StaticSprites.h"
#include "Inventory.h"
#include "StaingObject.h"

#include "ChestInventory.h"
#include "OvenInventory.h"

class Player : public Sprite
{
private:
	Functions functions;

public:
	// Инвентарь
	Inventory inventory;

	// Угол игрока
	int angle;
	bool isOpenInventory;
	int whatTypeInventoryOpen;
	int whatNumberInventoryOpen;

	float run;

	Player(){ }
	Player(std::shared_ptr<sf::RenderWindow> _rw, int _fieldSizeOne, std::string imageFileName, sf::Vector2f _position);

	std::vector<Button> buttons;


	// Ходьба игрока
	void Move();
	//Каждый кадр
	void Update();
	// Проверить наличие объекта перед игроком
	bool PutObject(std::vector<std::shared_ptr<StaingObject<OvenInventory>>> ovens,
		std::vector<std::shared_ptr<StaingObject<ChestInventory>>> chests);
	// Отрисовка
	void Draw(sf::Vector2f cameraPosition);
};

