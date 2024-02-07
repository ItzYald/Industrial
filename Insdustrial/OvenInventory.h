#pragma once


#include "Inventory.h"
#include "ObjectInventory.h"

class OvenInventory : public ObjectInventory
{
protected:
	// ������� �������� ������
	int whatBurn;
	int previousItemBurn2;
	// ������ � ����������
	std::vector<CellInInventory> cells;

public:
	// ������������ ������� (��� ��������� ������� �������� �������)
	int maxFuel;
	// �������
	int fuel;
	// ������� ������ ��� ����� ����� (�������� ��� �������������)
	void AllBurn();
	// ��������� ��� ����� ����� (�������� ��� �������������)
	void AllDraw();
	void Burn(){}
	void Draw(){}
	void Update(Inventory& playerInventory){}

};

