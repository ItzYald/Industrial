#pragma once
#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Functions/Functions.h"
#include "Functions/Button.h"

#include "Inventory.h"

#include "StaticSprites.h"


class ObjectInventory
{
protected:
	// Списко кнопок
	std::vector<Button> buttons;
	// Окно
	std::shared_ptr<sf::RenderWindow> rw;
	Functions functions;
	StaticSprites itemsSprites;
	// Позиция мыши
	sf::Vector2i mousePosition;

	virtual void Draw(Inventory& playerInventory) = 0;
};

