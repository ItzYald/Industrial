#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions.h"
#include "Button.h"
#include "Checks.h"

#include "StaticSprites.h"

struct ItemStruct
{
	int number;
	int quantity;
};

class Inventory
{
private:
	std::vector<Button> buttons;
	std::shared_ptr<sf::RenderWindow> rw;
	Functions functions;
	StaticSprites itemsSprites;
	std::vector<Checks> ch;

public:

	// Позиция мыши
	sf::Vector2i mousePosition;

	// Предметы в интерфейсе
	std::vector<std::vector<ItemStruct>> items;
	// Предмет перетаскиваемый мышкой
	ItemStruct mouseItem;

	int choseCell;	

	// Не используется
	Inventory(){ }
	// Конструктор
	Inventory(std::shared_ptr<sf::RenderWindow> _rw);

	void Draw();
	void DrawNear(int mouseWheel);
	

};

