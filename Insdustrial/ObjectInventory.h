#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/OldButton.h"

#include "StaticSprites.h"

#include "CellInInventory.h"

#include "Inventory.h"
#include "AllInventory.h"

class ObjectInventory : public AllInventory
{
public:
	// ��������� ���������
	virtual void Draw() = 0;
	// ������ (���� ����� ��������� �� ������)
	virtual void Next() = 0;
	/// <summary>���� ��������� ������</summary>
	/// <param name="playerInventory">��������� ������</param>
	virtual void Update(Inventory& playerInventory) = 0;

};

