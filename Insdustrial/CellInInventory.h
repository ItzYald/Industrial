#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Functions/Functions.h"
#include "Functions/Button.h"

struct ItemStruct
{
	int number;
	int quantity;
};

class CellInInventory
{
private:
	std::shared_ptr<sf::RenderWindow> rw;
	Functions functions;

public:
	// ����� �� ������ � ������
	bool put;
	// ����� �� ����� �� ������
	bool take;

	ItemStruct item;
	// ������
	Button button;
	// ������ ������
	std::vector<sf::Color> colorsInventory;
	CellInInventory(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f position, bool _put, bool _take);

	void LoadColorInventoryFromFile();
	void Update(ItemStruct& mouseItem);

};

