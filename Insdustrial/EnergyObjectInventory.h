#pragma once
#include "ObjectInventory.h"
#include "Inventory.h"

class EnergyObjectInventory : public ObjectInventory
{
public:
	float energy;
	int maxEnergy;

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

	virtual void Draw() = 0;
	// ������
	virtual void Next() = 0;
	/// <summary>������ ���������</summary>
	/// <param name="playerInventory">��������� ������</param>
	virtual void Update(Inventory& playerInventory) = 0;

};

