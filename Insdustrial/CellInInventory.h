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
public:
	int number;
	int quantity;
	// Кнопка
	Button button;
	// Список цветов
	std::vector<sf::Color> colorsInventory;
	//CellInInventory()
	//{
	//	LoadColorInventoryFromFile();
	//	button = Button(sf::Vector2f(100, 100), sf::Vector2f(64, 64), L"",
	//		colorsInventory[0], colorsInventory[1], colorsInventory[2], sf::Color::Transparent,
	//		sf::Color::Transparent, sf::Color::Transparent, 1, 2, 25);
	//}
	CellInInventory(sf::Vector2f position);

	void LoadColorInventoryFromFile();
	void RightClick(){ }

};

