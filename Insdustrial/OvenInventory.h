#pragma once
#include "Inventory.h"
#include "ObjectInventory.h"
#include "ProgressInventory.h"

class OvenInventory : public ObjectInventory
{
protected:
	// Сколько осталось гореть
	int previousItemBurn;
	// Ячейки с предметами
	std::vector<CellInInventory> cells;

	ProgressInventory progress;

public:
	// Максимальное топливо (для отрисовки сколько осталось топлива)
	int maxFuel;
	// Топливо
	float fuel;
	// Процесс работы для любой печки (угольной или электрической)
	void AllBurn();
	// Отрисовка для любой печки (угольной или электрической)
	void AllDraw();
	void Next(){ }
	void Burn(){}
	void Draw(){}
	void Update(Inventory& playerInventory){}

};

