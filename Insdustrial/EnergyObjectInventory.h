#pragma once
#include "ObjectInventory.h"
#include "Inventory.h"

class EnergyObjectInventory : public ObjectInventory
{
public:
	float energy;
	int maxEnergy;
	int power = 0;

	EnergyObjectInventory(){ }

	void AllDraw();

	virtual void Draw() = 0;

	void AllPlayUpdate();
	// Всегда
	virtual void PlayUpdate() = 0;

	void AllWhileOpen(Inventory& playerInventory);
	/// <summary>Логика инвентаря</summary>
	/// <param name="playerInventory">Инвентарь игрока</param>
	virtual void WhileOpen(Inventory& playerInventory) = 0;

};

