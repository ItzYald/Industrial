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
	// Топливо
	int fuel;
	// Максимальное топливо
	int maxFuel;
	// Сколько осталось гореть
	int whatBurn;
	int previousItemBurn;
	int previousItemBurn2;

public:
	// Ячейки с предметами
	std::vector<CellInInventory> cells;
	std::vector<ItemStruct> items;

	OvenInventory(){ }
	OvenInventory(std::shared_ptr<sf::RenderWindow> _rw);

	void AllBurn();
	void Burn();
	void Draw();
	void Update(Inventory& playerInventory);

};

