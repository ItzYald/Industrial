#pragma once


#include "Inventory.h"
#include "ObjectInventory.h"

class OvenInventory : public ObjectInventory
{
protected:
	// ������� �������� ������
	int whatBurn;
	int previousItemBurn;
	// ������ � ����������
	std::vector<CellInInventory> cells;

public:
	// ������������ ������� (��� ��������� ������� �������� �������)
	int maxFuel;
	// �������
	float fuel;
	// ������� ������ ��� ����� ����� (�������� ��� �������������)
	void AllBurn();
	// ��������� ��� ����� ����� (�������� ��� �������������)
	void AllDraw();
	void Burn(){}
	void Draw(){}
	void Update(Inventory& playerInventory){}

};

