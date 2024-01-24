#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "StaticSprites.h"

#include "Item.h"

#include "Functions/Functions.h"
#include "Functions/Button.h"

class CellInInventory
{
private:
	std::shared_ptr<sf::RenderWindow> rw;
	Functions functions;
	StaticSprites itemsSprites;

protected:

public:
	// ����� �� ������ � ������
	bool put;
	// ����� �� ����� �� ������
	bool take;

	//ItemStruct item;
	Item item;
	// ������
	Button button;
	// ������ ������
	std::vector<sf::Color> colorsInventory;
	CellInInventory(){ }
	CellInInventory(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f position, bool _put, bool _take);
	CellInInventory(std::shared_ptr<sf::RenderWindow> _rw, sf::Vector2f position, bool _put);

	void LoadColorInventoryFromFile();

	// ���������� ������
	void DrawCell();
	// ����� �� ������
	bool Take(Item& mouseItem);
	// ������ ����
	void Update(Item& mouseItem);

};

