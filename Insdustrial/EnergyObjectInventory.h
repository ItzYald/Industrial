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
	// ������
	virtual void PlayUpdate() = 0;

	void AllWhileOpen(Inventory& playerInventory);
	/// <summary>������ ���������</summary>
	/// <param name="playerInventory">��������� ������</param>
	virtual void WhileOpen(Inventory& playerInventory) = 0;

};

