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
	EnergyObjectInventory(
		std::shared_ptr<sf::RenderWindow> _rw, std::vector<sf::Color> _colorsInventory, int _maxEnergy)
	{
		rw = _rw;
		functions = Functions(rw);
		colorsInventory = _colorsInventory;

		maxEnergy = _maxEnergy;
		energy = 0;
	}

	void AllDraw();

	virtual void Draw() = 0;

	void AllNext();
	// Всегда
	virtual void Next() = 0;

	void AllUpdate(Inventory& playerInventory);
	/// <summary>Логика инвентаря</summary>
	/// <param name="playerInventory">Инвентарь игрока</param>
	virtual void Update(Inventory& playerInventory) = 0;

};

