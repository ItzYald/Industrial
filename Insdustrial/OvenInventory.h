#pragma once
#include "Inventory.h"
#include "ObjectInventory.h"
#include "ProgressInventory.h"

class OvenInventory : public ObjectInventory
{
protected:
	// ������� �������� ������
	int previousItemBurn;
	// ������ � ����������
	std::vector<CellInInventory> cells;

	ProgressInventory progress;

public:
	// ������������ ������� (��� ��������� ������� �������� �������)
	int maxFuel;
	// �������
	float fuel;
	// ������� ������ ��� ����� ����� (�������� ��� �������������)
	void AllBurn();
	// ��������� ��� ����� ����� (�������� ��� �������������)
	void AllDraw();
	void Next(){ }
	void Burn(){}
	void Draw(){}
	void Update(Inventory& playerInventory){}

};

