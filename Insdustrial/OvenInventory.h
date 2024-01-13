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
	// Максимальное топливо (для отрисовки сколько осталось топлива)
	int maxFuel;
	// Сколько осталось гореть
	int whatBurn;
	int previousItemBurn2;
	// Ячейки с предметами
	std::vector<CellInInventory> cells;

public:
	// Процесс работы для любой печки (угольной или электрической)
	void AllBurn();
	// Отрисовка для любой печки (угольной или электрической)
	void AllDraw();
	void Burn(){}
	void Draw(){}
	void Update(Inventory& playerInventory){}

};

