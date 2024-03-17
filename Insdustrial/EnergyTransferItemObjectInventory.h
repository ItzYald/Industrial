#pragma once
#include "EnergyObjectInventory.h"
#include "TransferObjectInventory.h"

class EnergyTransferItemObjectInventory : public EnergyObjectInventory, public TransferObjectInventory
{
public:
	EnergyTransferItemObjectInventory(){}

	virtual void Draw() = 0;
	// ������
	virtual void PlayUpdate() = 0;
	/// <summary>������ ���������</summary>
	/// <param name="playerInventory">��������� ������</param>
	virtual void WhileOpen(Inventory& playerInventory) = 0;


};

