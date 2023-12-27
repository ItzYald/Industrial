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
	// Списко кнопок
	std::vector<Button> buttons;
	// Окно
	std::shared_ptr<sf::RenderWindow> rw;
	// Функции
	Functions functions;
	StaticSprites itemsSprites;
	// Позиция мыши
	sf::Vector2i mousePosition;

public:
	void DrawCommon(std::vector<std::vector<ItemStruct>> items);
	void DrawCommon(std::vector<ItemStruct> items);

};

