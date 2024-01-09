#pragma once
#include "Functions/Functions.h"
#include "Functions/Button.h"

// struct ItemStruct
// {
// 	int number;
// 	int quantity;
// };

class CellInInventory
{
public:
	int number;
	int quantity;
	// ������
	Button button;
	// ������ ������
	std::vector<sf::Color> colorsInventory;

	CellInInventory(sf::Vector2f position);

	void LoadColorInventoryFromFile();
	void RightClick();

};

