#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/Button.h"

//#include "Inventory.h"

#include "StaticSprites.h"

struct ItemStruct
{
	int number;
	int quantity;
};

class ObjectInventory
{
protected:
	// ������ ������
	std::vector<Button> buttons;
	// ����
	std::shared_ptr<sf::RenderWindow> rw;
	// �������
	Functions functions;
	StaticSprites itemsSprites;
	// ������� ����
	sf::Vector2i mousePosition;

public:
	void DrawCommon(std::vector<std::vector<ItemStruct>> items);
	void DrawCommon(std::vector<ItemStruct> items);

};

