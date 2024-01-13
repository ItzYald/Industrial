#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/Button.h"

#include "Inventory.h"
#include "ObjectInventory.h"

#include "StaticSprites.h"

class OvenInventory : public ObjectInventory
{
protected:
	// �������
	int fuel;
	// ������������ ������� (��� ��������� ������� �������� �������)
	int maxFuel;
	// ������� �������� ������
	int whatBurn;
	int previousItemBurn2;
	// ������ � ����������
	std::vector<CellInInventory> cells;

public:
	// ������� ������ ��� ����� ����� (�������� ��� �������������)
	void AllBurn();
	// ��������� ��� ����� ����� (�������� ��� �������������)
	void AllDraw();
	void Burn(){}
	void Draw(){}
	void Update(Inventory& playerInventory){}

};

