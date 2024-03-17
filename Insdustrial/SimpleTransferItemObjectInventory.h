#pragma once
#include "ObjectInventory.h"
#include "TransferObjectInventory.h"

class SimpleTransferItemObjectInventory : public ObjectInventory, public TransferObjectInventory
{
	// Отрисовка инвентаря
	virtual void Draw() = 0;
	// Всегда (даже когда инвентарь не открыт)
	virtual void PlayUpdate() = 0;
	/// <summary>Пока инвентарь открыт</summary>
	/// <param name="playerInventory">Инвентарь игрока</param>
	virtual void WhileOpen(Inventory& playerInventory) = 0;
};

