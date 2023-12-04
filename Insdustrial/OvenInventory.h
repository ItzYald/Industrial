#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions.h"
#include "Button.h"

#include "Inventory.h"

#include "StaticSprites.h"

class OvenInventory
{
	// ������ ������
	std::vector<Button> buttons;
	// ����
	std::shared_ptr<sf::RenderWindow> rw;
	Functions functions;
	StaticSprites itemsSprites;
	// ������� ����
	sf::Vector2i mousePosition;

	// ������� ����� �����
	int fuel;
	int whatBurn;

public:
	std::vector<ItemStruct> items;

	OvenInventory(){ }
	OvenInventory(std::shared_ptr<sf::RenderWindow> _rw);

	void Burn(Inventory& playerInventory);
	void Draw(Inventory &playerInventory);

};

