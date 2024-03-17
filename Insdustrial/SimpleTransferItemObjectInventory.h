#pragma once
#include "ObjectInventory.h"
#include "TransferObjectInventory.h"

class SimpleTransferItemObjectInventory : public ObjectInventory, public TransferObjectInventory
{
	// ��������� ���������
	virtual void Draw() = 0;
	// ������ (���� ����� ��������� �� ������)
	virtual void PlayUpdate() = 0;
	/// <summary>���� ��������� ������</summary>
	/// <param name="playerInventory">��������� ������</param>
	virtual void WhileOpen(Inventory& playerInventory) = 0;
};

