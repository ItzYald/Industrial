#pragma once
#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/Button.h"

#include "Inventory.h"
#include "ObjectInventory.h"

#include "StaticSprites.h"

class ChestInventory : ObjectInventory
{
	// Ячейки с предметами
	std::vector<std::vector<CellInInventory>> cells;

public:

	ChestInventory(){}
	//ChestInventory(std::shared_ptr<sf::RenderWindow> _rw);
	ChestInventory(std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory);

	// Работа с ячейками
	void Update(Inventory& playerInventory);

};

