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
protected:
	// Топливо
	int fuel;
	// Сколько осталось гореть
	int whatBurn;
	int previousItemBurn2;
	// Ячейки с предметами
	std::vector<CellInInventory> cells;

public:

	void AllBurn();
	virtual void Burn() = 0;
	virtual void Draw() = 0;
	virtual void Update(Inventory& playerInventory) = 0;

};

