#pragma once


#include "Inventory.h"
#include "ObjectInventory.h"

class OvenInventory : public ObjectInventory
{
protected:
	// Сколько осталось гореть
	int whatBurn;
	int previousItemBurn2;
	// Ячейки с предметами
	std::vector<CellInInventory> cells;

public:
	// Максимальное топливо (для отрисовки сколько осталось топлива)
	int maxFuel;
	// Топливо
	int fuel;
	// Процесс работы для любой печки (угольной или электрической)
	void AllBurn();
	// Отрисовка для любой печки (угольной или электрической)
	void AllDraw();
	void Burn(){}
	void Draw(){}
	void Update(Inventory& playerInventory){}

};

