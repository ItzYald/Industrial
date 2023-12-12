#pragma once
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

class ChestInventory : ObjectInventory
{
	std::vector<std::vector<ItemStruct>> items;

public:

	ChestInventory(){}
	ChestInventory(std::shared_ptr<sf::RenderWindow> _rw);

	void Draw(Inventory& playerInventory);

};
