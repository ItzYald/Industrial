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

class OvenInventory : public ObjectInventory
{
	// Сколько можно сжечь
	int fuel;
	int maxFuel;
	int whatBurn;

public:

	std::vector<ItemStruct> items;
	int previousItemBurn;

	OvenInventory(){ }
	OvenInventory(std::shared_ptr<sf::RenderWindow> _rw);

	void Burn(Inventory& playerInventory);
	void Draw(Inventory& playerInventory);

};

