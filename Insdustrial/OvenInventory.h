#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions.h"
#include "Button.h"

#include "Inventory.h"
#include "ObjectInventory.h"

#include "StaticSprites.h"

class OvenInventory : public ObjectInventory
{
	// Сколько можно сжечь
	int fuel;
	int whatBurn;

public:
	std::vector<ItemStruct> items;

	OvenInventory(){ }
	OvenInventory(std::shared_ptr<sf::RenderWindow> _rw);

	void Burn(Inventory& playerInventory);
	void Draw(Inventory &playerInventory);

};

