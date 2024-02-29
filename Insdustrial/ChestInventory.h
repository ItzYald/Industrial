#pragma once
#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/OldButton.h"

#include "Inventory.h"
#include "ObjectInventory.h"

#include "StaticSprites.h"

class ChestInventory : public ObjectInventory
{
	// Ячейки с предметами
	std::vector<std::vector<CellInInventory>> cells;

public:

	ChestInventory(){}
	ChestInventory(std::shared_ptr<sf::RenderWindow> _rw,
		std::vector<sf::Color> _colorsInventory, std::vector<sf::Texture*>& _textures);

	void PlayUpdate() override{ }
	void Draw() override;
	// Работа с ячейками
	void WhileOpen(Inventory& playerInventory) override;

};

