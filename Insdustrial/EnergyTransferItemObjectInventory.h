#pragma once
#include "EnergyObjectInventory.h"
#include "TransferObjectInventory.h"

class EnergyTransferItemObjectInventory : public EnergyObjectInventory, public TransferObjectInventory
{
public:
	EnergyTransferItemObjectInventory(){}

	virtual void Draw() = 0;
	// Всегда
	virtual void PlayUpdate() = 0;
	/// <summary>Логика инвентаря</summary>
	/// <param name="playerInventory">Инвентарь игрока</param>
	virtual void WhileOpen(Inventory& playerInventory) = 0;


};

